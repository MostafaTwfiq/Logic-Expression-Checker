#include "LogicInfixCalculator.h"

#define NOT_PRIORITY 3;
#define AND_PRIORITY 2;
#define OR_PRIORITY 1;

typedef enum ArgType {
    OPERATOR, VARIABLE, VALUE, OPEN_PARENTHESES, CLOSED_PARENTHESES, NONE
} ArgType;


ArgType checkArgType(char *arg);
int getOperatorPriority(char *operator);
short operatorIsRightAssociative(char *operator);

void freeVariableHolder(void *variableHolder) {
    VariableHolder *vh = (VariableHolder *) variableHolder;
    free(vh->var);
    free(variableHolder);
}

int variableHolderCmpVar(void *vh1, void *vh2) {
    return strcmp(((VariableHolder *)vh1)->var, (char *) vh2);
}


void operatorCase(char *operator, Stack *operatorsStack, Queue *postfixQueue) {

    if (stackIsEmpty(operatorsStack)) {
        stackPush(operatorsStack, generateCharPointerP(operator, strlen(operator)));
        return;
    }

    int prevPriority = getOperatorPriority(stackPeek(operatorsStack));
    int currentPriority = getOperatorPriority(operator);

    if (
            currentPriority > prevPriority
    || (currentPriority == prevPriority && operatorIsRightAssociative(operator))
    ) {

        stackPush(operatorsStack, generateCharPointerP(operator, strlen(operator)));

    }

    else {

        while (!stackIsEmpty(operatorsStack) && currentPriority < getOperatorPriority(stackPeek(operatorsStack)))
            queueEnqueue(postfixQueue, stackPop(operatorsStack));

        stackPush(operatorsStack, generateCharPointerP(operator, strlen(operator)));

    }

}

void valueCase(Queue *postfixQueue, int value) {
    queueEnqueue(postfixQueue, intToCharArr(value));
}

void openParenthesesCase(Stack *operatorsStack) {
    stackPush(operatorsStack, generateCharPointerC('('));
}

short closedParenthesesCase(Stack *operatorsStack, Queue *postfixQueue) {

    if (!stackIsEmpty(operatorsStack) && !strcmp(stackPeek(operatorsStack), "("))
        return 1;

    while (!stackIsEmpty(operatorsStack) && strcmp(stackPeek(operatorsStack), "(") != 0)
        queueEnqueue(postfixQueue, stackPop(operatorsStack));

    if (stackIsEmpty(operatorsStack))
        return 1;

    free(stackPop(operatorsStack));

    return 0;

}

short performOperator(char *operator, Stack *valuesStack) {

    if (!strcmp(operator, "!")) {

        if (stackGetLength(valuesStack) < 1)
            return 1;

        char *valueC = (char *)stackPeek(valuesStack);
        !strcmp(valueC, "0") ? strcpy(valueC, "1") : strcpy(valueC, "0");

    } else if (!strcmp(operator, ".")) {

        if (stackGetLength(valuesStack) < 2)
            return 1;

        char *fValueC = (char *) stackPop(valuesStack);
        char *sValueC = (char *) stackPop(valuesStack);
        char *ans = malloc(sizeof(char) * 2);
        sprintf(ans, "%d", atoi(fValueC) & atoi(sValueC));
        stackPush(valuesStack, ans);
        free(fValueC);
        free(sValueC);

    } else if (!strcmp(operator, "+")) {

        if (stackGetLength(valuesStack) < 2)
            return 1;

        char *fValueC = (char *) stackPop(valuesStack);
        char *sValueC = (char *) stackPop(valuesStack);
        char *ans = malloc(sizeof(char) * 2);
        sprintf(ans, "%d", atoi(fValueC) | atoi(sValueC));
        stackPush(valuesStack, ans);
        free(fValueC);
        free(sValueC);

    }

    return 0;

}

short calculatePostfix(Queue *postfixQueue) {

    Stack *valuesStack = stackInitialization(free);
    while (!queueIsEmpty(postfixQueue)) {

        ArgType argType = checkArgType(queuePeek(postfixQueue));

        switch (argType) {
            case VALUE:
                stackPush(valuesStack, queueDequeue(postfixQueue));
                break;
            case OPERATOR: {
                short errorFlag = performOperator(queuePeek(postfixQueue), valuesStack);
                free(queueDequeue(postfixQueue));
                if (errorFlag) {
                    destroyStack(valuesStack);
                    return -1;
                }

                break;
            }

        }

    }

    if (stackGetLength(valuesStack) != 1) {
        destroyStack(valuesStack);
        return -1;
    }

    short finalValue = (short ) atoi((char *) stackPeek(valuesStack));
    destroyStack(valuesStack);
    destroyQueue(postfixQueue);

    return finalValue;

}

Vector *splitInfix(String *infix) {

    String *current = stringInitialization(1);
    Vector *splittedInfix = vectorInitialization(10, destroyString, stringCompareS);
    ArgType currentArgType = NONE;

    for (int i = 0; i < stringGetLength(infix); i++) {

        if (stringGet(infix, i) == ' ') {

            if (stringGetLength(current) != 0) {
                vectorAdd(splittedInfix, current);
                current = stringInitialization(1);
            }

            continue;
        }

        currentArgType = checkArgType(infix->string + i);

        switch (currentArgType) {
            case OPERATOR:
            case OPEN_PARENTHESES:
            case CLOSED_PARENTHESES: {

                if (stringGetLength(current) != 0) {
                    vectorAdd(splittedInfix, current);
                    current = stringInitialization(1);
                }

                stringAppendChar(current, stringGet(infix, i));
                vectorAdd(splittedInfix, current);
                current = stringInitialization(1);
                break;

            }
            case VALUE:
            case VARIABLE: {
                stringAppendChar(current, stringGet(infix, i));
                break;
            }

        }

    }

    if (stringGetLength(current) != 0)
        vectorAdd(splittedInfix, current);
    else
        destroyString(current);

    return splittedInfix;

}

Queue *generatePostfix(String *infix, Vector *varHolder) {

    Vector *splittedInfix = splitInfix(infix);

    Stack *operatorsStack = stackInitialization(free);
    Queue *postfixQueue = queueInitialization(free);

    for (int i = 0; i < vectorGetLength(splittedInfix); i++) {

        char *currentArg = ((String *) vectorGet(splittedInfix, i))->string;

        ArgType argType = checkArgType(currentArg);

        switch (argType) {
            case OPERATOR:
                operatorCase(currentArg, operatorsStack, postfixQueue);
                break;
            case VALUE:
                valueCase(postfixQueue, atoi(currentArg));
                break;
            case VARIABLE: {

                int variableIndex = vectorGetIndex(varHolder, currentArg);
                if (variableIndex < 0) {
                    destroyVector(splittedInfix);
                    destroyStack(operatorsStack);
                    destroyQueue(postfixQueue);
                    return NULL;
                }

                VariableHolder *vh = vectorGet(varHolder, variableIndex);

                valueCase(postfixQueue, vh->val);

                break;

            }
            case OPEN_PARENTHESES:
                openParenthesesCase(operatorsStack);
                break;
            case CLOSED_PARENTHESES: {
                short errorFlag = closedParenthesesCase(operatorsStack, postfixQueue);
                if (errorFlag) {
                    destroyVector(splittedInfix);
                    destroyStack(operatorsStack);
                    destroyQueue(postfixQueue);
                    return NULL;
                }

                break;
            }

        }

    }

    while (!stackIsEmpty(operatorsStack))
        queueEnqueue(postfixQueue, stackPop(operatorsStack));

    destroyVector(splittedInfix);
    destroyStack(operatorsStack);

    return postfixQueue;

}

int getOperatorPriority(char *operator) {

    if (!strcmp(operator, "!"))
        return NOT_PRIORITY;
    if (!strcmp(operator, "."))
        return AND_PRIORITY;
    if (!strcmp(operator, "+"))
        return OR_PRIORITY;

    return 0;

}

short operatorIsRightAssociative(char *operator) {

    if      (
                !strncmp(operator, "!", 1)
            )
    {
        return 1;
    }

    return 0;

}


short isOperator(char *operator) {
    if      (
            !strncmp(operator, "!", 1)
            || !strncmp(operator, ".", 1)
            || !strncmp(operator, "+", 1)
            )
    {
        return 1;
    }

    return 0;

}

ArgType checkArgType(char *arg) {

    if (isOperator(arg))
        return OPERATOR;

    else if (!strncmp(arg, "0", 1) || !strncmp(arg, "1", 1))
        return VALUE;

    else if (!strncmp(arg, "(", 1))
        return OPEN_PARENTHESES;

    else if (!strncmp(arg, ")", 1))
        return CLOSED_PARENTHESES;

    else
        return VARIABLE;

}

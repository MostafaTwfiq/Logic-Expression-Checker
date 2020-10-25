#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataStructure-Algorithms/DataStructure/Strings/Headers/String.h"
#include "DataStructure-Algorithms/FilesHandler/Headers/TxtFileLoader.h"
#include "DataStructure-Algorithms/DataStructure/Lists/Headers/Vector.h"
#include "LogicInfixCalculator.h"

void checkExpression(String *fileDir);

int main() {

    String *fileDir = stringInitialization(100);

    printf("**Use the key word exit, to end the program.**\n\n");
    while (1) {
        printf("Please enter the file path: ");
        stringScanInput(fileDir, stdin);

        if (!stringCompareC(fileDir, "exit"))
            break;

        checkExpression(fileDir);

        clearString(fileDir);

    }

    destroyString(fileDir);

    return 0;

}


short fileIsExist(char *fileDir) {

    FILE *file = fopen(fileDir, "r");
    if (file == NULL)
        return 0;

    fclose(file);

    return 1;

}

Vector *loadVariables(TxtFileLoader *txtFileLoader) {

    String *variablesString = txtLoaderReadLineS(txtFileLoader, 0);
    Vector *variablesV = stringSplit(variablesString, " ,\t");

    destroyString(variablesString);

    return variablesV;

}

short fileIsValid(TxtFileLoader *txtFileLoader, int linesNum, int numOfVars) {

    if ( (1 << numOfVars) != linesNum - 2 )
        return 0;

    Vector *lines = txtLoaderReadFileLines(txtFileLoader);
    vectorRemoveAtIndex(lines, 0);
    vectorRemoveAtIndex(lines, 0);

    String *currentLine = NULL;
    for (int i = 0; i < vectorGetLength(lines); i++) {

        currentLine = (String *) vectorGet(lines, i);

        if (!stringEqualsC(currentLine, "0") && !stringEqualsC(currentLine, "1")) {
            destroyVector(lines);
            return 0;
        }

    }

    destroyVector(lines);

    return 1;

}

void checkExpression(String *fileDir) {

    if (!fileIsExist(fileDir->string)) {
        printf("File not found.\n");
        return;
    }

    TxtFileLoader *txtFileLoader = txtFileLoaderInitialization(fileDir->string);

    int linesCounter = txtLoaderCountLines(txtFileLoader);
    if (linesCounter < 3) {
        printf("File is not valid.\n");
        destroyTxtFileLoader(txtFileLoader);
        return;
    }

    Vector *variablesV = loadVariables(txtFileLoader);

    if (!fileIsValid(txtFileLoader, linesCounter, vectorGetLength(variablesV))) {
        printf("File is not valid.\n");
        destroyTxtFileLoader(txtFileLoader);
        destroyVector(variablesV);
        return;
    }

    String *expressionString = txtLoaderReadLineS(txtFileLoader, 1);

    Vector *values = txtLoaderReadFileLines(txtFileLoader);
    vectorRemoveAtIndex(values, 0);
    vectorRemoveAtIndex(values, 0);

    Vector *varsHolder = vectorInitialization(vectorGetLength(variablesV), freeVariableHolder, variableHolderCmpVar);
    for (int i = 0; i < vectorGetLength(variablesV); i++) {
        VariableHolder *variableHolder = (VariableHolder *) malloc(sizeof(VariableHolder));
        variableHolder->var = generateCharPointerP(((String *)vectorGet(variablesV, i))->string, strlen(((String *)vectorGet(variablesV, i))->string));
        variableHolder->val = 0;
        vectorAdd(varsHolder, variableHolder);
    }

    int numOfSubSets = 1 << vectorGetLength(variablesV);
    for (int i = 0; i < numOfSubSets; i++) {

        for (int j = 0; j < vectorGetLength(variablesV); j++) {

            if ((i & (1 << j)) != 0) {
                ((VariableHolder *) vectorGet(varsHolder, vectorGetLength(varsHolder) - 1 - j))->val = 1;
            } else {
                ((VariableHolder *) vectorGet(varsHolder, vectorGetLength(varsHolder) - 1 - j))->val = 0;
            }

        }

        Queue *postfix = generatePostfix(expressionString, varsHolder);
        if (postfix == NULL) {
            printf("The Expression is invalid.\n");
            destroyTxtFileLoader(txtFileLoader);
            destroyVector(variablesV);
            destroyVector(values);
            destroyVector(varsHolder);
            destroyString(expressionString);
            destroyQueue(postfix);
            return;
        }

        short ans = calculatePostfix(postfix);
        if (ans < 0) {
            printf("The Expression is invalid.\n");
            destroyTxtFileLoader(txtFileLoader);
            destroyVector(variablesV);
            destroyVector(values);
            destroyVector(varsHolder);
            destroyString(expressionString);
            destroyQueue(postfix);
            return;
        }

        printf("Expected: %d, Ans: %d  ---->  %d\n", atoi(((String *) vectorGet(values, i))->string), ans, i);
        if ( atoi(((String *) vectorGet(values, i))->string) != ans ) {
            printf("The circuit is not correct.\n");
            destroyTxtFileLoader(txtFileLoader);
            destroyVector(variablesV);
            destroyVector(values);
            destroyVector(varsHolder);
            destroyString(expressionString);
            destroyQueue(postfix);
            return;
        }

        destroyQueue(postfix);

    }

    printf("The circuit is correct.\n");

    destroyTxtFileLoader(txtFileLoader);
    destroyVector(variablesV);
    destroyVector(values);
    destroyVector(varsHolder);
    destroyString(expressionString);

}
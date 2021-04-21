#ifndef LOGICEXPRESSIONCHECKER_LOGICINFIXCALCULATOR_H
#define LOGICEXPRESSIONCHECKER_LOGICINFIXCALCULATOR_H

#include <stdlib.h>
#include <string.h>
#include "DataStructure-Algorithms/DataStructure/Strings/Headers/String.h"
#include "DataStructure-Algorithms/DataStructure/Lists/Headers/Vector.h"
#include "DataStructure-Algorithms/DataStructure/Stacks/Headers/Stack.h"
#include "DataStructure-Algorithms/DataStructure/Queues/Headers/Queue.h"
#include "DataStructure-Algorithms/Algorithms/ArraysAlg/Headers/CharArrayAlg.h"
#include "DataStructure-Algorithms/Algorithms/IntegersAlg/Headers/IntegerAlg.h"

typedef struct VariableHolder {
    char *var;
    short val;
} VariableHolder;

void freeVariableHolder(void *variableHolder);
int variableHolderCmpVar(const void *vh1, const void *vh2);
Queue *generatePostfix(String *infix, Vector *varHolder);
short calculatePostfix(Queue *postfixQueue);

#endif //LOGICEXPRESSIONCHECKER_LOGICINFIXCALCULATOR_H

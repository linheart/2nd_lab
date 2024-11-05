#ifndef CALC_H // CALC_H
#define CALC_H

#include "stack.h"

#include <iostream>

bool isOperator(auto &it);
std::string retrieveNum(auto &it);
void removeSpaces(std::string &expr);
int priority(char op);
void applyOperator(Stack<int> &values, char op);
int evalExpr(std::string &expr);

#endif // CALC_H

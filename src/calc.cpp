#include "../include/calc.h"

#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

bool isOperator(auto &it) {
  return it == '+' || it == '-' || it == '*' || it == '(' || it == ')';
}

string retrieveNum(auto &it) {
  string num;
  if (*it == '-') {
    num += '-';
    it++;
  }
  for (; !isOperator(*it) && *it; it++) {
    num += *it;
  }
  return num;
}

void removeSpaces(string &expr) {
  expr.erase(remove(expr.begin(), expr.end(), ' '), expr.end());
}

int priority(char op) {
  if (op == '+' || op == '-') {
    return 1;
  }
  if (op == '*') {
    return 2;
  }
  return 0;
}

void applyOperator(Stack<int> &values, char op) {
  if (values.size() < 2) {
    throw std::runtime_error("Err: not enough operands");
  }

  int right = values.top->data;
  values.pop();

  int left = values.top->data;
  values.pop();

  int result;

  if (op == '+') {
    result = left + right;
  } else if (op == '-') {
    result = left - right;
  } else if (op == '*') {
    result = left * right;
  }
  values.push(result);
}

int evalExpr(string &expr) {
  removeSpaces(expr);

  Stack<int> values;
  Stack<char> operators;

  for (auto it = expr.begin(); it != expr.end(); it++) {
    if (isdigit(*it) ||
        (*it == '-' && (it == expr.begin() || *prev(it) == '('))) {
      int num = stoi(retrieveNum(it));
      it--;
      if (*it - '0' != abs(num) % 10) {
        throw runtime_error("Err: Invalid number format");
      }
      values.push(num);
    } else if (isOperator(*it)) {
      if (*it == '(') {
        operators.push(*it);
      } else if (*it == ')') {
        while (!operators.isEmpty() && operators.top->data != '(') {
          applyOperator(values, operators.top->data);
          operators.pop();
        }

        if (operators.isEmpty() || operators.top->data != '(') {
          throw runtime_error("Err: bracket mismatch");
        }

        operators.pop();
      } else {
        while (!operators.isEmpty() &&
               priority(operators.top->data) >= priority(*it)) {
          applyOperator(values, operators.top->data);
          operators.pop();
        }
        operators.push(*it);
      }
    } else {
      throw runtime_error("Err: invalid character in the expression");
    }
  }

  while (!operators.isEmpty()) {
    if (operators.top->data == '(') {
      throw runtime_error("Err: bracket mismatch");
    }
    applyOperator(values, operators.top->data);
    operators.pop();
  }

  if (values.size() != 1) {
    throw runtime_error("Err: incorrect expression");
  }
  return values.top->data;
}
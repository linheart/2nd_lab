#include "../include/calc.h"
#include "../include/stack.h"

using namespace std;

int main() {
  string expr;
  getline(cin, expr);
  try {
    int res = evalExpr(expr);
    cout << res << endl;
  } catch (const exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}

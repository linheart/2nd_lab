#include <iostream>

using namespace std;

int init(int val);
void err(string promt);
int counting_dup(int n);

int main() {
  int n;
  n = init(n);

  if (n <= 0)
    err("Invalid input");

  cout << counting_dup(n) << endl;

  return 0;
}

int counting_dup(int n) {
  int a = init(a), count = 0;
  int b = a;

  for (int i = 0; i < n - 1; i++) {
    a = init(a);
    if (a == b)
      count++;
    b = a;
  }
  return count;
}

void err(string promt) {
  cerr << promt << endl;
  exit(EXIT_FAILURE);
}

int init(int val) {
  if (!(cin >> val))
    err("Invalid input");
  return val;
}

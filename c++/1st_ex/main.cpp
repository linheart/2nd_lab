#include <cmath>
#include <iostream>

using namespace std;

int init(int val);
int func(int S, int M, int N);

int main() {

  int S, M, N;

  S = init(S);
  N = init(N);
  M = init(M);

  cout << func(S, M, N) << endl;
  return 0;
}

void err(string promt) {
  cerr << promt << endl;
  exit(EXIT_FAILURE);
}

int init(int val) {
  if (!(cin >> val) || val <= 0)
    err("Invalid input");

  return val;
}

int func(int S, int M, int N) {
  if (S * M > (S - S / 7) * N) {
    return -1;
  }
  return ceil((double)S * M / N);
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

unsigned init(unsigned val);
void err(string promt);
void cmp(const vector<unsigned> arr, unsigned v);
unsigned counting_steps(const vector<unsigned> arr, unsigned v);

int main() {
  unsigned n;
  n = init(n);

  vector<unsigned> arr(n);
  for (unsigned i = 0; i < n; i++) {
    arr[i] = init(arr[i]);
  }

  unsigned v;
  v = init(v);

  cmp(arr, v);

  cout << counting_steps(arr, v) << endl;

  return 0;
}

void err(string promt) {
  cerr << promt << endl;
  exit(EXIT_FAILURE);
}

unsigned init(unsigned val) {
  if (!(cin >> val))
    err("Invalid input");
  return val;
}

void cmp(const vector<unsigned> arr, unsigned v) {
  if (*max_element(arr.begin(), arr.end()) > v)
    err("The volume of the watering can is not enough to water the flower");
}

unsigned counting_steps(const vector<unsigned> arr, unsigned v) {
  unsigned count = 0;
  unsigned tmp = v;

  for (size_t i = 0; i < arr.size(); i++) {
    if (tmp < arr[i]) {
      tmp = v;
      count += (i) * 2;
    }
    count++;
    tmp -= arr[i];
  }

  return count;
}

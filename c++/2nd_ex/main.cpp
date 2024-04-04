#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int init(int val);
void err(string promt);
void cmp(const vector<int> arr, int v);
int counting_steps(const vector<int> arr, int v);

int main() {
  int n;
  n = init(n);

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = init(arr[i]);
  }

  int v;
  v = init(v);

  cmp(arr, v);

  cout << counting_steps(arr, v) << endl;

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

void cmp(const vector<int> arr, int v) {
  if (*max_element(arr.begin(), arr.end()) > v)
    err("The volume of the watering can is not enough to water the flower");
}

int counting_steps(const vector<int> arr, int v) {
  int count = 0;
  int tmp = v;

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

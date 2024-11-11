#include <iostream>

#include "hash_table.h"

using namespace std;

bool isIsomorphic(const string &s1, const string &s2) {
  if (s1.length() != s2.length()) return false;

  HT<char, int> ht1, ht2;

  for (size_t i = 0; i < s1.length(); i++) {
    if (!ht1[s1[i]]) {
      ht1[s1[i]] = i;
    }
    if (!ht2[s2[i]]) {
      ht2[s2[i]] = i;
    }

    if (ht1[s1[i]] != ht2[s2[i]]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s1, s2;

  cin >> s1 >> s2;

  cout << (isIsomorphic(s1, s2) ? "True" : "False") << endl;
  return 0;
}
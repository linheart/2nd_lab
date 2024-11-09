#include "arr.h"

using namespace std;

bool isMatch(Array &str, Array &pattern) {
  size_t i = 0, j = 0;

  for (; i < str.length; i++, j++) {
    if (pattern.data[j] == '*') {
      if (!pattern.data[j + 1]) {
        return true;
      }

      for (; i < str.length && str.data[i] != pattern.data[j + 1]; i++)
        ;
      j++;

    } else if (pattern.data[j] != '?' && str.data[i] != pattern.data[j]) {
      return false;
    }
  }

  for (; j < pattern.length && pattern.data[j] == '*'; j++)
    ;
  return j == pattern.length;
}

int main() {
  Array str;
  Array pattern;

  string tmp;

  getline(cin, tmp);
  str.append(tmp);

  getline(cin, tmp);
  pattern.append(tmp);

  cout << (isMatch(str, pattern) ? "True" : "False") << endl;

  return 0;
}

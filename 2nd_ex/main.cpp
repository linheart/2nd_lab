#include "set.h"

using namespace std;

int main() {
  Set<string> set1;
  set1.insert("asd");

  Set<string> set2;
  set2.insert("lol");
  set2.insert("kek");

  Set<string> *set = setUnion(set1, set2);

  for (size_t i = 0; i < 100; i++) {
    if (set->node[i]) {
      Node<string> *cur = set->node[i];
      while (cur) {
        cout << cur->value << " ";
        cur = cur->next;
      }
      cout << endl;
    }
  }

  delete set;

  return 0;
}

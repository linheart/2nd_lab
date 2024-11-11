#include <iostream>
#include <sstream>

#include "tree.h"

using namespace std;

void printTree(const string &prefix, Tree *node, bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isLeft ? "|--" : "L--");
    cout << node->key << endl;
    printTree(prefix + (isLeft ? "|   " : "    "), node->right, true);
    printTree(prefix + (isLeft ? "|   " : "    "), node->left, false);
  }
}

int main() {
  string nums;
  string num;
  getline(cin, nums);
  istringstream stream(nums);

  try {
    if (!(stream >> num)) {
      throw runtime_error("Err: empty input");
    }

    Tree tree(atoi(num.c_str()));

    while (stream >> num) {
      int n = atoi(num.c_str());
      tree.insert(n);
    }

    cout << "Tree structure:" << endl;
    printTree("", &tree, false);
    cout << tree.getHeight() << endl;

  } catch (const exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
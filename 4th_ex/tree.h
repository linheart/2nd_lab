#ifndef TREE_H  // TREE_H
#define TREE_H

struct Tree {
  int key;
  Tree *left;
  Tree *right;

  Tree(int val = 0) : key(val), left(nullptr), right(nullptr) {}
  ~Tree() {
    delete left;
    delete right;
  }

  Tree *insert(int val) {
    if (val < key) {
      left = left ? left->insert(val) : new Tree(val);
    } else if (val > key) {
      right = right ? right->insert(val) : new Tree(val);
    }

    return this;
  }

  int getHeight() {
    int lHeight = left ? left->getHeight() : 0;
    int rHeight = right ? right->getHeight() : 0;
    return 1 + std::max(lHeight, rHeight);
  }
};

#endif  // TREE_H
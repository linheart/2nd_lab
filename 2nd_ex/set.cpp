#include "set.h"

void insertNodes(Node *src, Set *res) {
  Node *current = src;
  while (current) {
    res->insert(current->value);
    current = current->next;
  }
}

Set *setUnion(Set &set1, Set &set2) {
  Set *set = new Set;

  for (size_t i = 0; i < SIZE; i++) {
    if (set1.node[i]) {
      insertNodes(set1.node[i], set);
    }
    if (set2.node[i]) {
      insertNodes(set2.node[i], set);
    }
  }

  return set;
}

Set *filterSet(Set &set1, Set &set2, bool predicate) {

  Set *set = new Set;

  for (size_t i = 0; i < SIZE; i++) {
    Node *node1 = set1.node[i];

    while (node1) {
      Node *node2 = set2.node[i];

      while (node2 && node1->value != node2->value) {
        node2 = node2->next;
      }

      if ((node2 && predicate) || (!node2 && !predicate)) {
        set->insert(node1->value);
      }

      node1 = node1->next;
    }
  }

  return set;
}

Set *setIntersection(Set &set1, Set &set2) {
  return filterSet(set1, set2, true);
}

Set *setDifference(Set &set1, Set &set2) {
  return filterSet(set1, set2, false);
}

#ifndef SET_H // SET_H
#define SET_H

#include <iostream>

#define SIZE 100

struct Node {
  std::string value;
  Node *next;

  Node(const std::string &v) : value(v), next(nullptr) {}
  ~Node() { delete next; }
};

struct Set {
  Node **node;

  Set() : node(nullptr) {
    node = new Node *[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
      node[i] = nullptr;
    }
  }

  ~Set() {
    for (int i = 0; i < SIZE; i++) {
      Node *current = node[i];
      while (current != nullptr) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
      }
      node[i] = nullptr;
    }
    delete[] node;
  }

  unsigned hashFunction(const std::string &value) {
    unsigned hash = 0;
    for (auto ch : value) {
      hash = (hash * 31 + ch) % SIZE;
    }
    return hash;
  }

  void insert(const std::string &value) {
    unsigned index = hashFunction(value);
    Node *current = node[index];

    while (current) {
      if (current->value == value) {
        return;
      }

      current = current->next;
    }

    Node *newNode = new Node(value);
    newNode->next = node[index];
    node[index] = newNode;
  }

  void remove(const std::string &value) {
    unsigned index = hashFunction(value);
    Node *current = node[index];
    Node *tmp = nullptr;

    while (current && current->value != value) {
      tmp = current;
      current = current->next;
    }

    if (!current) {
      return;
    }

    if (tmp) {
      tmp->next = current->next;
    } else {
      node[index] = current->next;
    }

    delete current;
  }

  bool find(const std::string &value) {
    unsigned index = hashFunction(value);
    Node *current = node[index];

    while (current && current->value != value) {
      current = current->next;
    }

    return current != nullptr;
  }
};

Set *setUnion(Set &set1, Set &set2);
Set *setIntersection(Set &set1, Set &set2);
Set *setDifference(Set &set1, Set &set2);

#endif // SET_H

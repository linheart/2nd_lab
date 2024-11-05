#ifndef SET_H // SET_H
#define SET_H

#include <functional>
#include <iostream>

#define SIZE 100

template <typename T> struct Node {
  T value;
  Node *next;

  Node(const T &v) : value(v), next(nullptr) {}
  ~Node() { delete next; }
};

template <typename T> struct Set {
  Node<T> **node;

  Set() : node(nullptr) {
    node = new Node<T> *[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
      node[i] = nullptr;
    }
  }

  ~Set() {
    for (int i = 0; i < SIZE; i++) {
      Node<T> *current = node[i];
      while (current != nullptr) {
        Node<T> *tmp = current;
        current = current->next;
        delete tmp;
      }
      node[i] = nullptr;
    }
    delete[] node;
  }

  unsigned hashFunction(const T &key) {
    std::hash<T> h;
    return h(key) % SIZE;
  }

  void insert(const T &value) {
    unsigned index = hashFunction(value);
    Node<T> *current = node[index];

    while (current) {
      if (current->value == value) {
        return;
      }

      current = current->next;
    }

    Node<T> *newNode = new Node<T>(value);
    newNode->next = node[index];
    node[index] = newNode;
  }

  void remove(const T &value) {
    unsigned index = hashFunction(value);
    Node<T> *current = node[index];
    Node<T> *tmp = nullptr;

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
};

template <typename T> void insertNodes(Node<T> *source, Set<T> *result) {
  Node<T> *current = source;
  while (current) {
    result->insert(current->value);
    current = current->next;
  }
}

template <typename T> Set<T> *setUnion(Set<T> &set1, Set<T> &set2) {
  Set<T> *set = new Set<T>;

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

#endif // SET_H

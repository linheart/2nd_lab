#ifndef HASH_TABLE_H  // HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>

#define SIZE 100

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node *next;

  Node(K k, V v) : key(k), value(v), next(nullptr) {}
  ~Node() { delete next; }
};

template <typename K, typename V>
struct HT {
  Node<K, V> **node;

  HT() : node(nullptr) {
    node = new Node<K, V> *[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
      node[i] = nullptr;
    }
  }

  ~HT() {
    for (int i = 0; i < SIZE; i++) {
      Node<K, V> *current = node[i];
      while (current != nullptr) {
        Node<K, V> *tmp = current;
        current = current->next;
        delete tmp;
      }
      node[i] = nullptr;
    }
    delete[] node;
  }

  unsigned hashFunction(K key) {
    std::hash<K> hasher;
    return hasher(key) % SIZE;
  }

  V &operator[](K key) {
    unsigned index = hashFunction(key);
    Node<K, V> *current = node[index];

    while (current) {
      if (current->key == key) {
        return current->value;
      }

      current = current->next;
    }

    Node<K, V> *newNode = new Node<K, V>(key, V());
    newNode->next = node[index];
    node[index] = newNode;
    return newNode->value;
  }
};

#endif  // HASH_TABLE_H

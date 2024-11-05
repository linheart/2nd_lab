#ifndef STACK_H // STACK_H
#define STACK_H

#include <iostream>

template <typename T>
struct Node {
  T data;
  Node *next;

  Node (const T &val, Node *node) : data(val), next(node) {}
  ~Node () {
    delete next;
  }
};

template <typename T>
struct Stack {
  Node<T> *top;
  Stack () : top(nullptr) {}
  ~Stack () {
    delete top;
  }

  void push(const T &val) {
    Node<T> *newNode = new Node<T>(val, top);
    this->top = newNode;
  }

  void pop() {
    if (top) {
    Node<T> *tmp = top;
        top = top->next;

        tmp->next = nullptr;
        delete tmp;
    }
  }

  bool isEmpty() {
    return top ? false : true;
  }

  size_t size() {
    size_t size = 0;
    Node<T> *current = top;
    while (current) {
      size++;
      current= current->next;
    }
    return size;
  }
};


#endif // STACK_H
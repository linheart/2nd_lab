#ifndef ARR_H // ARR_H
#define ARR_H

#include <iostream>

struct Array {
  size_t capacity;
  size_t length;
  char *data;

  Array() : capacity(10), length(0), data(new char[10]) { data[0] = '\0'; }
  ~Array() { delete[] data; }

  void resize(size_t newCapacity) {
    char *newData = new char[newCapacity];

    for (size_t i = 0; i < length; ++i) {
      newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    data[length] = '\0';
  }

  void append(const std::string value) {
    if (length + value.size() >= capacity) {
      resize(capacity + value.size());
    }

    for (auto ch : value) {
      data[length++] = ch;
    }

    data[length] = '\0';
  }
};

#endif // ARR_H

// Copyright 2023 Elton Soares
#include <iostream>

// Fixed size ArrayStack
template <class T> class ArrayStack {
public:
  ArrayStack();
  ArrayStack(ArrayStack &&) = default;
  ArrayStack(const ArrayStack &) = default;
  ArrayStack &operator=(ArrayStack &&) = default;
  ArrayStack &operator=(const ArrayStack &) = default;
  ~ArrayStack();

  T Push(T element);
  T Pop();
  bool StackEmpty();

private:
  int ArraySize;
  int top;
  T *arr[];
};

template <class T> ArrayStack<T>::ArrayStack() {
  this->arr = new T[10];
  this->top = this->arr[0];
  this->arrSize = 10;
}

template <class T> T ArrayStack<T>::Push(T element) {
  if (this->top < this->arrSize) {
    this->arr[this->top] = element;
    this->top++;
    return this->arr[this->top - 1];
  }
}

template <class T> T ArrayStack<T>::Pop() {
  if (this->StackEmpty()) {
    return -1;
  } else {
    this->top--;
    return this->arr[this->top + 1];
  }
}

template <class T> bool ArrayStack<T>::StackEmpty() {
  if (this->top = 0)
    return true;
  else
    return false;
}

// Copyright 2023 Elton Soares
#include <iostream>
#include <string>

using std::string;

template <class T> class Node {
public:
  Node(T data);
  T GetData();
  Node* GetNext();
  T SetData();
  Node* SetNext();

private:
  T data;
  Node *next;
};

template <class T> Node<T>::Node(T data) { this->data = data; }

template <class T> class LinkedList {
public:
  LinkedList(T data);
  void Display(Node<T> *node);
  int Count();

private:
  Node<T> *head;
  Node<T> *last;
};

template <class T> LinkedList<T>::LinkedList(T data) {
  this->head = new Node<T>(data);
}

template <class T> void LinkedList<T>::Display(Node<T> *node) {
  if (node != NULL) {
    std::cout << "Data: " << node->GetData() << std::endl;
    Display(node->GetNext());
  }
}

template <class T> int LinkedList<T>::Count() {
  Node<T> *p = this->head;
  int count = 0;

  while(p != NULL) {
    count++;
    p = p->GetNext();
  }

  return count;
}

int main(int argc, char *argv[]) {
  LinkedList<std::string> l1("Primeiro");

  l1.Display();

  return 0;
}

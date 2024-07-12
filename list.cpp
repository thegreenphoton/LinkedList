#include "list.h"

class Node {
  int data;
  Node* next;
  Node() {
    data = 0;
    next = nullptr;
  }
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class List {
  public: 
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
    int size();
    const Node* getFirst();
    const Node* getLast();
    List& operator=(const List& other);
    List(const List& other) //copy constructor
    List(); //default constructor
    ~List(); //destructor
  private: 
    Node* first;
    Node* last;
};
  

List::List() {
  first = nullptr;
  last = nullptr;
}

const Node* List::getFirst() {
  return first;
}

const Node* List::getLast() {
  return last;
}

void List::push_front(int data) {
  if (first == nullptr && last == nullptr) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    first = newNode;
    last = newNode;
    return;
  }
  Node* newNode = new Node;
  newNode->next = first;
  newNode->data = data;
  first = newNode;
}

void List::push_back(int data) {
  if (first == nullptr && last == nullptr) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    first = newNode;
    last = newNode;
    return;
  }
  Node* newNode = new Node;
  newNode->data = data;
  last->next = newNode;
  newNode->next = nullptr;
  last = newNode;
}

void List::pop_front() {
  if (!first && !last) {
    }
  if (first == last) {
    delete first;
    first = nullptr;
    last = nullptr;
    return;
  }
  Node* newNode;
  newNode = first;
  first = first->next;
  delete newNode;
}

void List::pop_back {
  if (!first && !last) {
  }
  if (first == last) {
    delete first;
    first = nullptr;
    last = nullptr;
    return;
  }
  Node* current;
  current = first;
  while (current->next != last) {
    current = current->next;
  }
  delete last;
  last = current;
  last->next = nullptr;
}

int List::size() {
  int size = 0;
  Node* current = first;
  while (current != nullptr) {
    size++;
    current = current->next;
  }
  return size;
}

List::~List() {
  Node* current;
  current = this->first;
  while (current) {
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
  }
}

List& List::operator=(const List& other) {
  if (this == &other) {
    return *this;
  }
  Node* current = this->first;
  while (current) {
    Node* nextNode = current->next;
    delete current;
    current = nextNode;
  }
  Node* otherNode = other.first;
  first = nullptr;
  last = nullptr;
  while (otherNode != nullptr) {
    push_back(otherNode->data);
    otherNode = otherNode->next;
  }
  return *this;
}

List::List(const List& other) {
  Node* otherNode = other.first;
  first = nullptr;
  last = nullptr;
  while (otherNode != nullptr) {
    push_back(otherNode->data);
    otherNode = otherNode->next;
  }
}
  

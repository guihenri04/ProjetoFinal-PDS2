#include <iostream>
#include "list.hpp"

void List::insertNode(int data) {
  Node* aux = new Node;
  aux->data = data;
  aux->next = nullptr;
  if (head == nullptr) {
    head = aux;
    tail = aux;
  } else {
    tail->next = aux;
    tail = aux;
  }
}

void List::display() {
  Node *aux = head;
  while (aux != nullptr) {
    cout << aux->data << " ";
    aux = aux->next;
  }
  cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte()
{
    if (head == nullptr || head -> next == nullptr )
    return;
    

    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current != nullptr) 
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
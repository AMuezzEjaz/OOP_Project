#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "GameObject.hpp"

// Common list methods:
// append, insert
// remove, delete
// access, index
// slice
// size
// find
#include "linkedlist.hpp"
linkedlist::linkedlist()
{
  head = nullptr;
  tail = nullptr;
}

int linkedlist::size()
{
  //std::cout << "Size called\n";
  Node *temp = this->head;
  int count = 0;
  //std::cout << "inside size \n";
  while (temp != nullptr)
  {
    temp = temp->next;
    count++;
    //std::cout << "in loop\n";
  }
  //std::cout << "size calculated" << count << '\n';
  return count;
  return 0;
}

// destructor.
linkedlist::~linkedlist()
{
  // Deallocate all nodes in the list.
  Node *current = head;
  Node *ahead;
  while (current != nullptr)
  {
    ahead = current->next;
    delete[] current->data;
    delete current;
    current = ahead;
  }
  head = nullptr;
}

void linkedlist::deletelist()
{
    // Deallocate all nodes in the list.
      Node *current = head;
      Node *ahead;
      while (current != nullptr)
      {
        ahead = current->next;
        delete[] current->data;
        delete current;
        current = ahead;
      }
      head = nullptr;
}

void linkedlist::cnode(GameObject *value)
{
  Node *temp = new Node;
  temp->data = value;
  temp->next = nullptr;
  if (head == nullptr)
  {
    head = new Node(value);
    tail = head;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

void linkedlist::renderall()
{
  Node *temp = head->next;
  while (temp != NULL)
  {
    if (temp->data != NULL)
    {
      temp->data->Render();
    }
    temp = temp->next;
  }
}
void linkedlist::remove(Node *m)
{
  Node *temp = new Node;
  Node *previous = new Node;
  temp = head;
  previous = head;
  while (temp != nullptr)
  {
    if (temp == m)
    {
      if (temp->next != nullptr)
      {
        previous->next = temp->next;
        delete temp->data;
        free(temp);
      }
      else
      {
        tail = previous;
        previous->next = nullptr;
        delete temp->data;
        free(temp);
      }
    }
    else
    {
      previous = temp;
      temp = temp->next;
    }
  }
}
void linkedlist::deleteNode(Node *head, Node *n)
{
  // When node to be deleted is head node
  if (head == n)
  { 
    return;
  }
  // When not first node, follow
  // find the previous node
  Node *prev = head;
  while (prev->next != NULL && prev->next != n)
    prev = prev->next;

  // Check if node really exists in Linked List
  if (prev->next == NULL)
  {
    //std::cout << "Given node is not present in Linked List\n";
    return;
  }

  // Remove node from Linked List
  prev->next = prev->next->next;

  // Free memory
  free(n);

  return;
}

#include "Node.hpp"
#pragma once
#include <iostream>

class linkedlist
{

public:
    Node *head;
    Node *tail;
    linkedlist();
    void delete_move();
    void renderall();
    void cnode(GameObject *val); //adds node to the list
    int size(); // deletes the tail node
    ~linkedlist();
    Node *get_head() { return head; }
    void remove(Node *);
    void deleteNode(Node *head, Node *n);
    void deletelist();
};

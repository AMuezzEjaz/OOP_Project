#pragma once
#include "GameObject.hpp"

class Node
{
public:
    GameObject *data;
    Node *next;

    Node(GameObject *data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->data = nullptr;
        this->next = nullptr;
    }
};

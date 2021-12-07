/***************************************************************************
** File: Node.hpp
** Author: Jake Statz
** Date: 6/07/2020
** Description: The node class and function prototypes
**************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
public:
    T num; //Stores the node number value
    Node* next; //Stores the pointer to the next node

    /********************************************************
    ** Function: Constructor
    ** Description: Initializes the node class
    ** Input: value, pointer
    ** Pre-Conditions: none
    ** Post-Conditions: Initializes
    ********************************************************/
    Node(T v = 0, Node* n = nullptr);
};

template <typename T>
Node<T>::Node(T v, Node<T>* n) {
    num = v;
    next = n;
}

#endif

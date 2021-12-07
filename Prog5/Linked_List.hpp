/***************************************************************************
** File: Linked_List.hpp
** Author: Jake Statz
** Date: 6/07/2020
** Description: 
**************************************************************************/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>
#include "Node.hpp"

using namespace std;

template <typename T>
class Linked_List {
private:
    unsigned int length; //Number of nodes
    Node<T>* head; //Pointer to the first node

    /********************************************************
    ** Function: Mergesort
    ** Description: Mergesorts a list
    ** Input: List*, size
    ** Pre-Conditions: A list exists
    ** Post-Conditions: List is sorted
    ********************************************************/
    Node<T>* mergesort(Node<T>*, unsigned int);

    /********************************************************
    ** Function: Merge
    ** Description: Combines two lists
    ** Input: Lists*, sizes
    ** Pre-Conditions: 2 lists 
    ** Post-Conditions: lists are combined and sorted 
    ********************************************************/
    Node<T>* merge(Node<T>*, unsigned int, Node<T>*, unsigned int);

    /********************************************************
    ** Function: Selection_sort
    ** Description: Sorts the list in ascending order using recursive selection sort
    ** Input: List*, size
    ** Pre-Conditions: A list exists
    ** Post-Conditions: List is sorted
    ********************************************************/
    Node<T>* selection_sort(Node<T>*);

    /********************************************************
    ** Function: is_prime
    ** Description: Determines if the number is prime
    ** Input: num
    ** Pre-Conditions: none
    ** Post-Conditions: Returns if the number is prime
    ********************************************************/
    bool is_prime(T);

public:
    /********************************************************
    ** Function: Constructor
    ** Description: Initializes The linked List
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: Initialized
    ********************************************************/
    Linked_List();

    /********************************************************
    ** Function: Copy constructor
    ** Description: Creates a new list and copies the old one
    ** Input: linked list
    ** Pre-Conditions: none
    ** Post-Conditions: Deep copies the old list
    ********************************************************/
    Linked_List(const Linked_List&);

    /********************************************************
    ** Function: Assignment operator overload
    ** Description: Creates a new list and copies the old one
    ** Input: linked list
    ** Pre-Conditions: none
    ** Post-Conditions: Deep copies the old list
    ********************************************************/
    Linked_List& operator=(const Linked_List&);

    /********************************************************
    ** Function: Destructor
    ** Description: Deletes the list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: No list
    ********************************************************/
    ~Linked_List();

    /********************************************************
    ** Function: get_length
    ** Description: Returns the length of the list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: Returns the length of the list
    ********************************************************/
    unsigned int get_length();

    /********************************************************
    ** Function: print
    ** Description: Prints the list
    ** Input: none
    ** Pre-Conditions: There is a list
    ** Post-Conditions: Prints the list
    ********************************************************/
    void print();

    /********************************************************
    ** Function: clear
    ** Description: Deletes the nodes in the list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: No more nodes
    ********************************************************/
    void clear();

    /********************************************************
    ** Function: push_front
    ** Description: Places a node at the front of the list
    ** Input: A node
    ** Pre-Conditions: none
    ** Post-Conditions: Appends the node to the list
    ********************************************************/
    unsigned int push_front(T);

    /********************************************************
    ** Function: push_back
    ** Description: Places a node at the back of the list
    ** Input: A node
    ** Pre-Conditions: none
    ** Post-Conditions: Appends the node to the list
    ********************************************************/
    unsigned int push_back(T);

    /********************************************************
    ** Function: insert
    ** Description: Places a node into a list
    ** Input: A node
    ** Pre-Conditions: none
    ** Post-Conditions: Places a node in a set spot in the list
    ********************************************************/
    unsigned int insert(T, unsigned int);

    /********************************************************
    ** Function: sort_ascending
    ** Description: Uses merge sort in ascending order
    ** Input: none
    ** Pre-Conditions: A list
    ** Post-Conditions: The sorted list
    ********************************************************/
    void sort_ascending();

    /********************************************************
    ** Function: sort_descending
    ** Description: Uses merge sort in descending order
    ** Input: none
    ** Pre-Conditions: A list
    ** Post-Conditions: The sorted list
    ********************************************************/
    void sort_descending();

    /********************************************************
    ** Function: num_primes
    ** Description: Counts the number of primes in a list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: Returns the number of prime numbers
    ********************************************************/
    unsigned int num_primes();
};

template <typename T>
Linked_List<T>::Linked_List() {
    length = 0;
    head = nullptr;
}

template <typename T>
Linked_List<T>::Linked_List(const Linked_List<T>& l) {
    length = l.length;
    if (l.head == nullptr) {
        head = nullptr;
        return;
    }
    head = new Node<T>(l.head->num);
    Node<T>* current_old = l.head;
    Node<T>* current_new = head;
    while (current_old->next != nullptr) {
        current_new->next = new Node<T>(current_old->next->num);
        current_old = current_old->next;
        current_new = current_new->next;
    }
    current_new->next = nullptr;
}

template <typename T>
Linked_List<T>& Linked_List<T>::operator=(const Linked_List<T>& old) {
    if (this == &old) return *this;
    clear();
    length = old.length;
    if (old.head == nullptr) {
        head = nullptr;
        return *this;
    }
    head = new Node<T>(old.head->num);
    Node<T>* current_old = old.head;
    Node<T>* current_new = head;
    while (current_old->next != nullptr) {
        current_new->next = new Node<T>(current_old->next->num);
        current_old = current_old->next;
        current_new = current_new->next;
    }
    current_new->next = nullptr;
    return *this;
}

template <typename T>
Linked_List<T>::~Linked_List() {
    clear();
}

template <typename T>
unsigned int Linked_List<T>::get_length() {
    return length;
}

template <typename T>
void Linked_List<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->num << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void Linked_List<T>::clear() {
    Node<T>* to_delete = head;
    while (head != nullptr) {
        to_delete = head->next;
        delete head;
        head = to_delete;
    }
    length = 0;
}

template <typename T>
unsigned int Linked_List<T>::push_front(T v) {
    head = new Node<T>(v, head);
    return ++length;
}

template <typename T>
unsigned int Linked_List<T>::push_back(T v) {
    Node<T>* last = head;
    if (last == nullptr) {
        head = new Node<T>(v);
    }
    else {
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new Node<T>(v);
    }
    return ++length;
}

template <typename T>
unsigned int Linked_List<T>::insert(T v, unsigned int index) {
    if (index == 0) {
        head = new Node<T>(v, head);
    }
    else if (index > length || index < 0) {
        throw new out_of_range("Out of range.");
    }
    else {
        Node<T>* before = head;
        for (int i = 0; i < index - 1; ++i) {
            before = before->next;
        }
        before->next = new Node<T>(v, before->next);
    }
    return ++length;
}

template <typename T>
void Linked_List<T>::sort_ascending() {
    head = mergesort(head, length);
}

template <typename T>
void Linked_List<T>::sort_descending() {
    head = selection_sort(head);
}

template <typename T>
Node<T>* Linked_List<T>::mergesort(Node<T>* start, unsigned int size) {
    if (size <= 1) {
        start->next = nullptr;
        return start;
    }
    Node<T>* second = start;
    for (int i = 0; i < (size - 1) / 2 + 1; ++i) {
        second = second->next;
    }
    return merge(mergesort(start, (size - 1) / 2 + 1), (size - 1) / 2 + 1, mergesort(second, size / 2), size / 2);
}

template <typename T>
Node<T>* Linked_List<T>::merge(Node<T>* first, unsigned int first_size, Node<T>* second, unsigned int second_size) {
    Node<T>* new_head = first->num < second->num ? first : second;   //Tracks the head of the list
    Node<T>* before = nullptr;
    unsigned int i = 0, j = 0;

    while (i < first_size && j < second_size) {
        if (first->num < second->num) {
            before = first;
            if (first->next != nullptr) {
                first = first->next;
            }
            else {
                first->next = second;
            }
            ++i;
        }
        else {
            if (before != nullptr) before->next = second;
            before = second;
            second = second->next;
            before->next = first;
            ++j;
        }
    }
    return new_head;
}

template <typename T>
Node<T>* Linked_List<T>::selection_sort(Node<T>* first) {
    if (first->next == nullptr) {
        return first;
    }
    Node<T>* current = first;
    Node<T>* before = nullptr;
    Node<T>* max = first;
    while (current != nullptr) {
        if (current->next != nullptr && current->next->num > max->num) {
            before = current;
            max = current->next;
        }
        current = current->next;
    }
    if (before != nullptr) {
        before->next = max->next;
        max->next = first;
    }
    max->next = selection_sort(max->next);
    return max;
}

template <typename T>
bool Linked_List<T>::is_prime(T n) {
    if (n > 1) {
        for (int x = 2; x <= n / 2; ++x) {
            if (n % x == 0) return false;
        }
        return true;
    }
    return false;
}

template <typename T>
unsigned int Linked_List<T>::num_primes() {
    Node<T>* current = head;
    unsigned int count = 0;
    while (current != nullptr) {
        if (is_prime(current->num)) {
            ++count;
        }
        current = current->next;
    }
    return count;
}
#endif
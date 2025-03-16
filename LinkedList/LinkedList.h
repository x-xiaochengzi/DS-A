//
// Created by xzc on 2025/3/15.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<ostream>
#include<stdexcept>
template<typename T>
class LinkedList {
public:
    // EFFECTS: Constructs an empty list.
    LinkedList();

    // EFFECTS: Copy constructor
    LinkedList(const LinkedList &rhs);
    // EFFECTS: Free memory.
    ~LinkedList();

    // EFFECTS: Operator=
    LinkedList &operator=(const LinkedList& other);
    // EFFECTS:  Returns true if the list is empty.
    bool empty() const;

    // REQUIRES: the list is not empty
    // EFFECTS:  Returns (by reference) the first element.
    T& front();

    // EFFECTS:  Inserts data at the front of the list.
    void push_front(const T &data);
    // REQUIRES: The list is not empty
    // EFFECTS:  Removes the first element.
    void pop_front();
    // MODIFIES: os
    // EFFECTS:  Prints the items in the list, each followed by a space.
    void print(std::ostream& os) const;
    // EFFECTS: Returns the size of the list.
    size_t size() const;
    // EFFECTS: Inserts data at the end of the list.
    void push_back(const T &data);
    // REQUIRES: The list is not empty
    // EFFECTS: Removes the last element
    void pop_back();

private:
    struct Node {
        T data;
        Node *prev;
        Node *next;
    };
    Node *sentinel;
    size_t _size;
    void pop_all();
    void push_all(const LinkedList &other);
};

#include"LinkedList.tpp"

#endif //LINKEDLIST_H

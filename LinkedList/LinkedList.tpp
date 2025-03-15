//
// Created by xzc on 2025/3/15.
//

// EFFECTS: Constructs an empty list.
template<typename T>
LinkedList<T>::LinkedList():sentinel(new Node{0, nullptr, nullptr}), _size(0) {
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList &rhs):sentinel(new Node{0, nullptr, nullptr}), _size(0) {
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    push_all(rhs);
}

template<typename T>
LinkedList<T>::~LinkedList() {
    pop_all();
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &other) {
    // self-check
    if (this == &other) {
        return *this;
    }
    pop_all();
    push_all(other);
    return *this;
}


// EFFECTS:  Returns true if the list is empty.
template<typename T>
bool LinkedList<T>::empty() const {
    return _size == 0;
}

// REQUIRES: the list is not empty
// EFFECTS:  Returns (by reference) the first element.
template<typename T>
T& LinkedList<T>::front() {
    if (empty()) {
        throw std::runtime_error("Error: An empty list");
    }
    return sentinel->next->data;
}

// EFFECTS:  Inserts data at the front of the list.
template<typename  T>
void LinkedList<T>::push_front(T data) {
    Node *node = new Node {data, sentinel, sentinel->next};
    sentinel->next->prev = node;
    sentinel->next = node;
    _size++;
}

// REQUIRES: The list is not empty
// EFFECTS:  Removes the first element.
template<typename T>
void LinkedList<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("Error: Attempted to pop from an empty list");
    }
    Node *victim = sentinel->next;
    sentinel->next = victim->next;
    victim->next->prev = sentinel;
    victim->next = nullptr;
    victim->prev = nullptr;
    delete victim;
    _size--;
}


// MODIFIES: os
// EFFECTS:  Prints the items in the list, each followed by a space.
template<typename  T>
void LinkedList<T>::print(std::ostream& os) const {
    const Node *node = sentinel->next;
    while (node != sentinel) {
        os << node->data <<" ";
        node = node->next;
    }
}

template<typename  T>
// EFFECTS: Returns the size of the list.
size_t LinkedList<T>::size() const {
    return _size;
}

template<typename T>
// EFFECTS: Inserts data at the end of the list.
void LinkedList<T>::push_back(T data) {
    Node *node = new Node {data, sentinel->prev, sentinel};
    sentinel->prev->next = node;
    sentinel->prev = node;
    _size++;

}
// REQUIRES: The list is not empty
// EFFECTS: Removes the last element
template<typename T>
void LinkedList<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Error: Attempted to pop from an empty list");
    }
    _size--;
    Node *victim = sentinel->prev;
    victim->prev->next = sentinel;
    sentinel->prev= victim->prev;
    victim->prev = nullptr;
    victim->next = nullptr;
    delete victim;

}

template<typename T>
void LinkedList<T>::push_all(const LinkedList &other) {
    Node *node_ptr = other.sentinel->next;
    while (node_ptr != other.sentinel) {
        push_front(node_ptr->data);
        node_ptr = node_ptr->next;
    }
}

template<typename T>
void LinkedList<T>::pop_all() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T> &list) {
    list.print(os);
    return os;
}

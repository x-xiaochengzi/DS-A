

//
// Created by xzc on 2025/3/16.
//
// EFFECTS: Creates a stack with the given capacity
template<typename T>
ArrayStack<T>::ArrayStack(size_t capacity)
    :capacity(capacity), base_ptr(capacity ? new T[capacity] : 0), top_ptr(base_ptr){}


// EFFECTS: Creates a stack from an existing stack
template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack &other)
    : capacity(other.capacity), base_ptr(new T[other.capacity]), top_ptr(base_ptr) {
    for (T *ptr = other.base_ptr; ptr != other.top_ptr; ++ptr, ++top_ptr) {
        *top_ptr = *ptr;
    }
}

// EFFECTS: Frees memory
template<typename T>
ArrayStack<T>::~ArrayStack() {
    delete []base_ptr;
    base_ptr = nullptr;
    top_ptr = nullptr;
}

// EFFECTS: Overloads the operator =
template<typename T>
ArrayStack<T> &ArrayStack<T>::operator=(const ArrayStack &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete []base_ptr;
    base_ptr = new T[rhs.capacity];
    top_ptr = base_ptr;
    capacity = rhs.capacity;
    for (T *ptr = rhs.base_ptr; ptr != rhs.top_ptr; ++ptr, ++top_ptr) {
        *top_ptr = *ptr;
    }
    return *this;
}

// EFFECTS: Adds val to the top of the stack
template<typename T>
void ArrayStack<T>::push(const T &val) {
    if (top_ptr - base_ptr == capacity) {
        resize(2 * capacity);
    }
    *top_ptr = val;
    ++top_ptr;
}

// EFFECTS: Removes the top element of the stack
template<typename T>
void ArrayStack<T>::pop() {
    if (base_ptr == top_ptr) {
        throw std::runtime_error("Stack underflow: cannot pop from an empty stack.");
    }
    --top_ptr;
    if (size() * 1.0 / capacity <= 0.25) {
        resize(capacity / 2);
    }
}

// EFFECTS: Returns a reference to the top element of the stack
template<typename T>
T &ArrayStack<T>::top() {
    if (base_ptr == top_ptr) {
        throw std::runtime_error("Stack underflow: cannot access top of an empty stack.");
    }
    return *(top_ptr - 1);

}

// EFFECTS: Returns the size of the stack
template<typename T>
size_t ArrayStack<T>::size() const {
    return top_ptr - base_ptr;
}

// EFFECTS: Returns whether the stack is empty
template<typename T>
bool ArrayStack<T>::empty() const {
    return base_ptr == top_ptr;
}

// EFFECTS: Changes the capacity of the stack to the given capacity.
template<typename T>
void ArrayStack<T>::resize(size_t capacity) {
    T *new_base_ptr = new T[capacity];
    T *new_top_ptr = new_base_ptr;
    for (T *ptr = base_ptr; ptr != top_ptr; ++ptr, ++new_top_ptr) {
        *new_top_ptr = *ptr;
    }
    delete []base_ptr;
    base_ptr = new_base_ptr;
    top_ptr = new_top_ptr;
}

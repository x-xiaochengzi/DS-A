//
// Created by xzc on 2025/3/16.
//

#include <stdexcept>
// EFFECTS: Creates a queue with the given capacity.
template<typename T>
ArrayQueue<T>::ArrayQueue(size_t capacity)
    :capacity(capacity), size_(0), data(capacity ?new T[capacity] : nullptr), front_ptr(data), back_ptr(data) {}

// EFFECTS: Creates a queue from the existing queue.
template<typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue &other)
    : capacity(other.capacity), size_(other.size_),data(new T[capacity]), front_ptr(data), back_ptr(data) {
    for (size_t i = 0; i < other.size_; ++i) {
        data[i] = other.data[(other.front_ptr - other.data + i) % other.capacity];
    }
    back_ptr = data + other.size_;
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] data;
}

template<typename T>
ArrayQueue<T> &ArrayQueue<T>::operator=(const ArrayQueue &rhs) {
    if (this != &rhs) {
        delete[] data;

        capacity = rhs.capacity;
        size_ = rhs.size_;
        data = new T[capacity];
        front_ptr = data;
        for (size_t i = 0; i < rhs.size_; ++i) {
            data[i] = rhs.data[(rhs.front_ptr - rhs.data + i) % rhs.capacity];
        }
        back_ptr = data + rhs.size_;
    }
    return *this;
}

template<typename T>
void ArrayQueue<T>::push(const T &val) {
    if (size_ == capacity) {
        resize(2 * capacity);
    }
    *back_ptr = val;
    back_ptr = data + (back_ptr - data + 1) % capacity;
    ++size_;
}

template<typename T>
void ArrayQueue<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Queue underflow");
    }
    front_ptr = data + (front_ptr + 1 - data) % capacity;
    --size_;
}

template<typename T>
T &ArrayQueue<T>::front() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }

    return *front_ptr;
}

template<typename T>
size_t ArrayQueue<T>::size() const {
    return size_;
}

template<typename T>
bool ArrayQueue<T>::empty() const {
    return size_ == 0;
}

template<typename T>
void ArrayQueue<T>::resize(size_t new_capacity) {
    T *new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data[(back_ptr - data + i) % capacity];
    }
    delete[] data;
    data = new_data;
    front_ptr = data;
    back_ptr = front_ptr + size_;
    capacity = new_capacity;
}

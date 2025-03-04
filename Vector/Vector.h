//
// Created by xzc on 2025/3/4.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <cstdint>
#include <stdexcept>
#include <iostream>
// Vector.h

template<typename T>
class Vector {
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vec);
public:
    // EFFECTS: Create an empty vector
    Vector();

    // EFFECTS: Create a vector with the given capacity
    Vector(int32_t capacity);

    // EFFECTS: Create a vector by the given vector
    Vector(const Vector &other);

    // EFFECTS: Release Resources
    ~Vector();
    
    // EFFECTS: Insert the given value to the end of a vector
    void push_back(const T &val);

    // EFFECTS: Insert the given value to the given position of a vector
    void insert(int32_t pos, const T &val);

    // EFFECTS: Remove the last element
    void pop_back();

    // EFFECTS: Remove the element at the given position
    void erase(int32_t pos);

    // EFFECTS: Return the reference of the element at the given position
    T &at(int32_t pos);

    // EFFECTS: const version of 'at()'
    const T &at(int32_t pos) const;

    // EFFECTS: Copy one vector to the other vector
    Vector &operator=(const Vector& rhs);

    // EFFECTS: Return the element at given position by subscript operator
    T &operator[](int32_t pos);

    // EFFECTS: const version of '[]'
    const T &operator[](int32_t pos) const;

    // EFFECTS: Return the number of elements stored in the vector
    int32_t size() const;

    // EFFECTS: Judge whether the vector is empty
    bool empty() const;

private:
    T *data;  // store elements
    int32_t _size; // the number of current valid  elements
    int32_t capacity; // the maximum number of elements that can be accommodated.

private:
    void swap_vector(Vector &other);
    void resize(int32_t capacity_in);
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vec);
#include "Vector.tpp"

#endif //VECTOR_H

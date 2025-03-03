//
// Created by xzc on 2025/3/4.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <cstdint>

template<typename T>
class Vector {
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



};



#endif //VECTOR_H

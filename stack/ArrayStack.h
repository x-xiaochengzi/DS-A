//
// Created by xzc on 2025/3/16.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <stdexcept>
#include "Stack.h"
template<typename T>
class ArrayStack: public Stack<T>{
public:
    // EFFECTS: Creates a stack with the given capacity
    ArrayStack(size_t capacity = 4);

    // EFFECTS: Creates a stack from an existing stack
    ArrayStack(const ArrayStack &other);

    // EFFECTS: Frees memory
    ~ArrayStack();

    // EFFECTS: Overloads the operator =
    ArrayStack &operator=(const ArrayStack &rhs);

    // EFFECTS: Adds val to the top of the stack
    virtual void push(const T &val) override;

    // EFFECTS: Removes the top element of the stack
    virtual void pop() override;

    // EFFECTS: Returns a reference to the top element of the stack
    virtual T &top() override;

    // EFFECTS: Returns the size of the stack
    virtual size_t size() const override;

    // EFFECTS: Returns whether the stack is empty
    virtual bool empty() const override;

private:
    size_t capacity;
    T *base_ptr;
    T *top_ptr;

    // EFFECTS: Changes the capacity of the stack to the given capacity.
    void resize(size_t capacity);
};


#include "ArrayStack.tpp"
#endif //ARRAYSTACK_H

//
// Created by xzc on 2025/3/16.
//

#ifndef STACK_H
#define STACK_H
#include<cstdint>
template<typename T>
class Stack{
public:
    // EFFECTS: Adds val to the top of the stack
    virtual void push(const T &val) = 0;

    // EFFECTS: Removes the top element of the stack
    virtual void pop() = 0;

    // EFFECTS: Returns a reference to the top element of the stack
    virtual T &top() = 0;

    // EFFECTS: Returns the size of the stack
    virtual size_t size() const = 0;

    // EFFECTS: Returns whether the stack is empty
    virtual bool empty() const = 0;

    virtual ~Stack() = 0;
};
#endif //STACK_H

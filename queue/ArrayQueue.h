//
// Created by xzc on 2025/3/16.
//

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include"Queue.h"

template<typename T>
class ArrayQueue: public Queue<T>{
public:
    // EFFECTS: Creates a queue with the given capacity.
    ArrayQueue(size_t capacity = 4);

    // EFFECTS: Creates a queue from the existing queue.
    ArrayQueue(const ArrayQueue &other);

    // EFFECTS: Frees memory
    ~ArrayQueue();

    // EFFECTS: Overloads the operator =.
    ArrayQueue &operator=(const ArrayQueue &rhs);

    // EFFECTS: Adds val to the back of the queue.
    virtual void push(const T &val) override;

    // EFFECTS: Removes top element from the front of the queue.
    virtual void pop() override;

    // EFFECTS: Returns a reference to the element at the front of the queue.
    virtual T &front() override;

    // EFFECTS: Returns the number of elements in the queue.
    virtual size_t size() const override;

    // EFFECTS: Checks if the queue is empty.
    virtual bool empty() const override;

private:
    size_t capacity;
    size_t size_;
    T *data;
    T *front_ptr;
    T *back_ptr;

    // EFFECTS: Resize the queue
    void resize(size_t new_capacity);
};


#include"ArrayQueue.tpp"
#endif //ARRAYQUEUE_H

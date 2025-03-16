//
// Created by xzc on 2025/3/16.
//
template<typename T>
class Queue{
public:
    // EFFECTS: Adds val to the back of the queue.
    virtual void push(const T &val) = 0;

    // EFFECTS: Removes top element from the front of the queue.
    virtual void pop() = 0;

    // EFFECTS: Returns a reference to the element at the front of the queue.
    virtual T &front() = 0;

    // EFFECTS: Returns the number of elements in the queue.
    virtual size_t size() const = 0;

    // EFFECTS: Checks if the queue is empty.
    virtual bool empty() const = 0;

    virtual ~Queue() = default;
};
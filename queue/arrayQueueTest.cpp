#include <iostream>
#include <cassert>
#include "ArrayQueue.h"

void test_default_constructor() {
    ArrayQueue<int> q;
    assert(q.empty());
    assert(q.size() == 0);
}

void test_push_pop_front() {
    ArrayQueue<int> q;
    q.push(10);
    assert(q.size() == 1);
    assert(q.front() == 10);

    q.pop();
    assert(q.empty());
    assert(q.size() == 0);
}

void test_multiple_push_pop() {
    ArrayQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    assert(q.size() == 3);
    assert(q.front() == 1);
    q.pop();

    assert(q.front() == 2);
    q.pop();

    q.push(4);
    assert(q.size() == 2);
    assert(q.front() == 3);
    q.pop();

    assert(q.front() == 4);
    q.pop();
    assert(q.empty());
}

void test_resize_on_full() {
    ArrayQueue<int> q(4);
    for (int i = 0; i < 4; ++i) {
        q.push(i);
    }
    q.push(4); // Trigger resize

    assert(q.size() == 5);
    for (int i = 0; i < 5; ++i) {
        assert(q.front() == i);
        q.pop();
    }
    assert(q.empty());
}

void test_circular_behavior_and_resize() {
    ArrayQueue<int> q(4);
    for (int i = 0; i < 4; ++i) {
        q.push(i);
    }
    q.pop(); // Remove 0
    q.pop(); // Remove 1
    q.push(4);
    q.push(5);

    assert(q.size() == 4);
    q.push(6); // Trigger resize to 8

    assert(q.size() == 5);
    assert(q.front() == 2);
    q.pop();

    assert(q.front() == 3);
    q.pop();

    assert(q.front() == 4);
    q.pop();

    assert(q.front() == 5);
    q.pop();

    assert(q.front() == 6);
    q.pop();
    assert(q.empty());
}

void test_copy_constructor() {
    ArrayQueue<int> q1;
    q1.push(1);
    q1.push(2);

    ArrayQueue<int> q2(q1);
    assert(q2.size() == 2);
    assert(q2.front() == 1);

    q1.pop();
    assert(q1.front() == 2);
    assert(q2.front() == 1);

    q2.pop();
    assert(q2.front() == 2);
}

void test_assignment_operator() {
    ArrayQueue<int> q1;
    q1.push(10);
    q1.push(20);

    ArrayQueue<int> q2;
    q2 = q1;
    assert(q2.size() == 2);
    assert(q2.front() == 10);

    q1.pop();
    assert(q1.front() == 20);
    assert(q2.front() == 10);
}

void test_self_assignment() {
    ArrayQueue<int> q;
    q.push(5);
    q = q; // Self-assignment

    assert(q.size() == 1);
    assert(q.front() == 5);
}

void testArrayQueue() {
    test_default_constructor();
    test_push_pop_front();
    test_multiple_push_pop();
    test_resize_on_full();
    test_circular_behavior_and_resize();
    test_copy_constructor();
    test_assignment_operator();
    test_self_assignment();

    std::cout << "All tests passed!" << std::endl;
}

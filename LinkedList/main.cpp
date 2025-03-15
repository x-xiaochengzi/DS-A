#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

void test_default_constructor() {
    LinkedList<int> list;
    std::cout << "Test Default Constructor: " << (list.empty() ? "PASS" : "FAIL") << std::endl;
}

void test_push_front() {
    LinkedList<int> list;
    list.push_front(10);
    std::cout << "Test Push Front: " << ((list.front() == 10 && list.size() == 1) ? "PASS" : "FAIL") << std::endl;
}

void test_pop_front() {
    LinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.pop_front();
    std::cout << "Test Pop Front: " << ((list.front() == 10 && list.size() == 1) ? "PASS" : "FAIL") << std::endl;
}

void test_pop_front_empty() {
    LinkedList<int> list;
    try {
        list.pop_front();
        std::cout << "Test Pop Front on Empty: FAIL" << std::endl;
    } catch (const std::runtime_error&) {
        std::cout << "Test Pop Front on Empty: PASS" << std::endl;
    }
}

void test_push_back() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    std::cout << "Test Push Back: " << ((list.size() == 2) ? "PASS" : "FAIL") << std::endl;
}

void test_pop_back() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    std::cout << "Test Pop Back: " << ((list.size() == 1 && list.front() == 10) ? "PASS" : "FAIL") << std::endl;
}

void test_pop_back_empty() {
    LinkedList<int> list;
    try {
        list.pop_back();
        std::cout << "Test Pop Back on Empty: FAIL" << std::endl;
    } catch (const std::runtime_error&) {
        std::cout << "Test Pop Back on Empty: PASS" << std::endl;
    }
}

void test_copy_constructor() {
    LinkedList<int> list;
    list.push_front(10);
    list.push_front(20);

    LinkedList<int> copy(list);

    std::cout << "Test Copy Constructor: " << ((copy.size() == 2 && copy.front() == 20) ? "PASS" : "FAIL") << std::endl;
}

void test_assignment_operator() {
    LinkedList<int> list1;
    list1.push_front(10);
    list1.push_front(20);

    LinkedList<int> list2;
    list2 = list1;

    std::cout << "Test Assignment Operator: " << ((list2.size() == 2 && list2.front() == 20) ? "PASS" : "FAIL") << std::endl;
}

void test_self_assignment() {
    LinkedList<int> list;
    list.push_front(10);
    list = list; // Self-assignment check
    std::cout << "Test Self Assignment: " << ((list.size() == 1 && list.front() == 10) ? "PASS" : "FAIL") << std::endl;
}

void test_print() {
    LinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    std::cout << "Test Print: ";
    list.print(std::cout);
    std::cout << " (Expected: 30 20 10)\n";
}

void test_large_scale() {
    LinkedList<int> list;
    for (int i = 0; i < 1000; i++) {
        list.push_back(i);
    }
    std::cout << "Test Large Scale: " << ((list.size() == 1000) ? "PASS" : "FAIL") << std::endl;
}

int main() {
    test_default_constructor();
    test_push_front();
    test_pop_front();
    test_pop_front_empty();
    test_push_back();
    test_pop_back();
    test_pop_back_empty();
    test_copy_constructor();
    test_assignment_operator();
    test_self_assignment();
    test_print();
    test_large_scale();

    return 0;
}

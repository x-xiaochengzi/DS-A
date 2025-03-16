#include<iostream>
#include <cassert>
#include "ArrayStack.h"

void test_push_pop() {
    ArrayStack<int> stack;

    // 测试 push 方法
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // 测试 size 方法
    size_t actual_size = stack.size();
    size_t expected_size = 3;
    assert(actual_size == expected_size && "Size should be 3 after pushing 3 elements");

    // 测试 top 方法
    int actual_top = stack.top();
    int expected_top = 30;
    assert(actual_top == expected_top && "Top element should be 30");

    // 测试 pop 方法
    stack.pop();
    actual_size = stack.size();
    expected_size = 2;
    assert(actual_size == expected_size && "Size should be 2 after popping one element");

    actual_top = stack.top();
    expected_top = 20;
    assert(actual_top == expected_top && "Top element should be 20 after popping one element");

    stack.pop();
    stack.pop();
    actual_size = stack.size();
    expected_size = 0;
    assert(actual_size == expected_size && "Size should be 0 after popping all elements");

    // 测试 empty 方法
    bool actual_empty = stack.empty();
    bool expected_empty = true;
    assert(actual_empty == expected_empty && "Stack should be empty after popping all elements");
}

void test_resize() {
    ArrayStack<int> stack(2);  // 初始容量为 2

    // 测试 push 方法，超过容量时应该自动扩容
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // 测试 size 方法
    size_t actual_size = stack.size();
    size_t expected_size = 3;
    assert(actual_size == expected_size && "Size should be 3 after pushing 3 elements");

    // 测试 top 方法
    int actual_top = stack.top();
    int expected_top = 3;
    assert(actual_top == expected_top && "Top element should be 3 after pushing 3 elements");
}

void test_underflow() {
    ArrayStack<int> stack;

    // 测试 pop 和 top 对空栈的处理，应该抛出异常
    try {
        stack.pop();
        assert(false && "Pop on empty stack should throw an exception");
    } catch (const std::runtime_error& e) {
        // Expected exception
    }

    try {
        stack.top();
        assert(false && "Top on empty stack should throw an exception");
    } catch (const std::runtime_error& e) {
        // Expected exception
    }
}

void test_copy_constructor() {
    ArrayStack<int> stack;
    stack.push(10);
    stack.push(20);

    // 使用拷贝构造函数创建新栈
    ArrayStack<int> copied_stack = stack;

    // 测试拷贝栈的 size 和 top
    size_t actual_size = copied_stack.size();
    size_t expected_size = 2;
    assert(actual_size == expected_size && "Size of copied stack should be 2");

    int actual_top = copied_stack.top();
    int expected_top = 20;
    assert(actual_top == expected_top && "Top of copied stack should be 20");
}

void test_assignment_operator() {
    ArrayStack<int> stack;
    stack.push(10);
    stack.push(20);

    // 使用赋值运算符创建新栈
    ArrayStack<int> assigned_stack;
    assigned_stack = stack;

    // 测试赋值栈的 size 和 top
    size_t actual_size = assigned_stack.size();
    size_t expected_size = 2;
    assert(actual_size == expected_size && "Size of assigned stack should be 2");

    int actual_top = assigned_stack.top();
    int expected_top = 20;
    assert(actual_top == expected_top && "Top of assigned stack should be 20");
}

void run() {
    test_push_pop();
    test_resize();
    test_underflow();
    test_copy_constructor();
    test_assignment_operator();
    std::cout << "All tests passed!" << std::endl;
}
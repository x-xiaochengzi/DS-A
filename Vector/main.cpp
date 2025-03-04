#include <iostream>
#include "Vector.h"

void test_basic_construction() {
    std::cout << "===== Test: Basic Construction =====" << std::endl;
    
    Vector<int> vec1;
    Vector<int> vec2(10);
    Vector<int> vec3(vec2);

    std::cout << "vec1 size: " << vec1.size() << " (Expected: 0)" << std::endl;
    std::cout << "vec2 size: " << vec2.size() << " (Expected: 0)" << std::endl;
    std::cout << "vec3 size: " << vec3.size() << " (Expected: 0)" << std::endl;
}

void test_push_back() {
    std::cout << "===== Test: push_back() =====" << std::endl;

    Vector<int> vec;
    for (int i = 1; i <= 5; i++) {
        vec.push_back(i * 10);
    }

    std::cout << "Vector: " << vec << " (Expected: 10 20 30 40 50)" << std::endl;
}

void test_insert() {
    std::cout << "===== Test: insert() =====" << std::endl;

    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec.insert(1, 15); // 在索引1插入 15
    vec.insert(0, 5);  // 在索引0插入 5

    std::cout << "Vector: " << vec << " (Expected: 5 10 15 20 30)" << std::endl;
}

void test_erase() {
    std::cout << "===== Test: erase() =====" << std::endl;

    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    vec.erase(1);  // 删除索引1的元素 (20)
    
    std::cout << "Vector: " << vec << " (Expected: 10 30 40)" << std::endl;
}

void test_pop_back() {
    std::cout << "===== Test: pop_back() =====" << std::endl;

    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec.pop_back();
    vec.pop_back();

    std::cout << "Vector: " << vec << " (Expected: 10)" << std::endl;
}

void test_at() {
    std::cout << "===== Test: at() and [] =====" << std::endl;

    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);

    std::cout << "vec[0]: " << vec.at(0) << " (Expected: 5)" << std::endl;
    std::cout << "vec[2]: " << vec[2] << " (Expected: 15)" << std::endl;
    
    try {
        std::cout << vec.at(5) << std::endl; // 超出范围，应该抛异常
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << " (Expected: Invalid index)" << std::endl;
    }
}

void test_resize() {
    std::cout << "===== Test: resize() =====" << std::endl;

    Vector<int> vec(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);  // 触发扩容

    std::cout << "Vector: " << vec << " (Expected: 1 2 3)" << std::endl;
}

void test_copy_and_assignment() {
    std::cout << "===== Test: Copy Constructor & Assignment =====" << std::endl;

    Vector<int> vec1;
    vec1.push_back(100);
    vec1.push_back(200);

    Vector<int> vec2 = vec1; // 复制构造
    Vector<int> vec3;
    vec3 = vec1; // 赋值操作

    std::cout << "vec1: " << vec1 << " (Expected: 100 200)" << std::endl;
    std::cout << "vec2: " << vec2 << " (Expected: 100 200)" << std::endl;
    std::cout << "vec3: " << vec3 << " (Expected: 100 200)" << std::endl;
}

void test_empty_and_size() {
    std::cout << "===== Test: empty() and size() =====" << std::endl;

    Vector<int> vec;
    std::cout << "Is empty? " << (vec.empty() ? "Yes" : "No") << " (Expected: Yes)" << std::endl;

    vec.push_back(1);
    vec.push_back(2);
    std::cout << "Size: " << vec.size() << " (Expected: 2)" << std::endl;
    std::cout << "Is empty? " << (vec.empty() ? "Yes" : "No") << " (Expected: No)" << std::endl;
}

int main() {
    test_basic_construction();
    test_push_back();
    test_insert();
    test_erase();
    test_pop_back();
    test_at();
    test_resize();
    test_copy_and_assignment();
    test_empty_and_size();

    return 0;
}

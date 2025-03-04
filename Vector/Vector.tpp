//
// Created by xzc on 2025/3/4.
//


// Vector.tpp

// EFFECTS: Create an empty vector
template<typename T>
Vector<T>::Vector()
    :data(nullptr), _size(0), capacity(0) {}

template<typename  T>
// EFFECTS: Create a vector with the given capacity
Vector<T>::Vector(int32_t capacity)
    :data(capacity != 0 ? new T[capacity] : nullptr),
    _size(0), capacity(capacity) {}

// The Big Three
template<typename  T>
// EFFECTS: Create a vector by the given vector
Vector<T>::Vector(const Vector &other)
    :data(new T[other.capacity]), _size(other._size),
    capacity(other.capacity) {
    // copy elements from other to this.
    for (int32_t i = 0; i < _size; ++i) {
        data[i] = other.data[i];
    }
}
template<typename  T>
// EFFECTS: Release Resources
Vector<T>::~Vector() {
    delete[] data;
    data = nullptr; // against double delete
}
template<typename  T>
// EFFECTS: Copy one vector to the other vector
// copy-swap method
Vector<T> &Vector<T>::operator=(const Vector& rhs) {
    // create temporary Vector that stores the contents of the new Vector
    // a deep copy is made since this uses the copy constructor
    Vector temp{rhs};
    // swap the original data with temp's data
    swap_vector(temp);
    // the old data is now stored in temp, and the
    // updated data is now stored in the current Vector (this)
    return *this;
}

template<typename  T>
// EFFECTS: Insert the given value to the end of a vector
void Vector<T>::push_back(const T& val) {
    if (_size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2); // 修正扩容逻辑
    }
    data[_size++] = val;
}

template<typename T>
// EFFECTS: Remove the last element
void Vector<T>::pop_back() {
    // check if this is empty
    if (!empty()) {
        _size--;
    }
}

template<typename T>
// EFFECTS: Return the reference of the element at the given position
T &Vector<T>::at(int32_t pos) {
    if (pos < _size) {
        return data[pos];
    }
    throw std::runtime_error{"Invalid index"};
}

template<typename T>
// EFFECTS: const version of 'at()'
const T &Vector<T>::at(int32_t pos) const{
    if (pos < _size) {
        return data[pos];
    }
    throw std::runtime_error{"Invalid index"};
}

template<typename T>
// EFFECTS: Return the element at given position by subscript operator
T &Vector<T>::operator[](int32_t pos) {
    if (pos < _size) {
        return data[pos];
    }
    throw std::runtime_error{"Invalid index"};
}

template<typename T>
// EFFECTS: const version of '[]'
const T &Vector<T>::operator[](int32_t pos) const {
    if (pos < _size) {
        return data[pos];
    }
    throw std::runtime_error{"Invalid index"};
}

template<typename T>
// EFFECTS: Insert the given value to the given position of a vector
void Vector<T>::insert(int32_t pos, const T& val) {
    if (pos < 0 || pos > _size) {
        throw std::runtime_error{"Invalid index"};
    }
    if (_size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    for (int32_t i = _size; i > pos; --i) { // 修正移动逻辑
        data[i] = data[i - 1];
    }
    data[pos] = val;
    _size++;
}

template<typename T>
// EFFECTS: Remove the element at the given position
void Vector<T>::erase(int32_t pos) {
    if (pos < _size) {
        // shift left
        for (int32_t i = pos; i < _size - 1; ++i) {
            data[i] = data[i + 1];
        }
        _size--;
        return;
    }
    throw std::runtime_error{"Invalid index"};

}
template<typename T>
// EFFECTS: Return the number of elements stored in the vector
int32_t Vector<T>::size() const {
    return _size;
}
template<typename T>
// EFFECTS: Judge whether the vector is empty
bool Vector<T>::empty() const {
    return _size == 0;
}

template<typename T>
void Vector<T>::swap_vector(Vector &other) {
    std::swap(data, other.data);
    std::swap(_size, other._size);
    std::swap(capacity, other.capacity);
}
template<typename T>
void Vector<T>::resize(int32_t capacity_in) {

    T *temp = new T[capacity_in];
    for (int32_t i = 0; i < _size; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = capacity_in;
}
template<typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vec) {
    for (int32_t i = 0; i < vec._size; ++i) {
        os << vec.data[i] << " ";
    }
    return os;
}
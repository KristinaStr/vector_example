//#include "vector.hpp"
#include <iostream>
#include <algorithm>
#include <cassert>


template <typename T>

class vector_t {
private:
    T *data_;
    std::size_t size_;
    std::size_t capacity_;
public:
    vector_t() {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    vector_t(vector_t<T> const &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (unsigned int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    vector_t operator=(vector_t<T> const &other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (unsigned int i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    bool operator==(vector_t<T> const &other) const {
        bool success = false;
        if (size_ == other.size_ && capacity_ == other.capacity_) {
            success = true;
            for (unsigned int i = 0; i < size_; i++) {
                if (data_[i] != other.data_[i]) {
                    success = false;
                    break;
                }
            }
        }
        return success;

    }

    ~vector_t() {
        delete[] data_;
    }

    std::size_t size() const {
        return size_;
    }

    std::size_t capacity() const {
        return capacity_;
    }

    void push_back(T value) {
        if (size_ == capacity_) {
            auto new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;

            T *mas = new T[new_capacity];
            for (unsigned int i = 0; i < size_; i++) {
                mas[i] = data_[i];
            }

            delete[] data_;

            capacity_ = new_capacity;
            data_ = mas;
        }

        data_[size_] = value;
        size_++;
    }

    void pop_back() {
        if (size_ == 0) return;
        size_--;
        if (size_ == 0 || size_ * 4 == capacity_) {
            T *mas;
            capacity_ = capacity_ / 2;
            mas = new T[capacity_];
            for (unsigned int i = 0; i < size_; i++) {
                mas[i] = data_[i];
            }
            delete[] data_;
            data_ = mas;
        }
    }

    T &operator[](std::size_t index) {
        return data_[index];
    }

    T operator[](std::size_t index) const {
        return data_[index];

    }
};

    bool operator!=(vector_t<T> const &lhs, vector_t<T> const &rhs) {

        bool success = true;
        if (lhs == rhs) {
            success = !success;
        }
        return success;

    }

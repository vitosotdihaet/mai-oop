#ifndef _VECTOR_H
#define _VECTOR_H

#include <cstdint>
#include <memory>


template <class T, class Allocator = std::allocator<T>>
class MyVector {
    private:
        Allocator allocator;
        size_t _size;
        size_t _capacity;
        T* data;

    public:
        MyVector() : _size(0), _capacity(0), data(nullptr) {}

        MyVector(const Allocator& alloc) : allocator(alloc), _size(0), _capacity(0), data(nullptr) {}

        ~MyVector() {
            clear();
            allocator.deallocate(data, _capacity);
        }

        void push_back(const T& value) {
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            }
            allocator.construct(data + _size, value);
            ++_size;
        }

        void pop_back() {
            if (_size > 0) {
                allocator.destroy(data + _size - 1);
                --_size;
            }
        }

        size_t size() const noexcept {
            return _size;
        }

        size_t capacity() const noexcept {
            return _capacity;
        }

        bool empty() const noexcept {
            return _size == 0;
        }

        T& operator[](size_t pos) {
            return data[pos];
        }

        const T& operator[](size_t pos) const {
            return data[pos];
        }

        void reserve(size_t new_capacity) {
            if (new_capacity > _capacity) {
                T* newData = allocator.allocate(new_capacity);
                for (size_t i = 0; i < _size; ++i) {
                    allocator.construct(newData + i, std::move_if_noexcept(data[i]));
                    allocator.destroy(data + i);
                }
                allocator.deallocate(data, _capacity);
                data = newData;
                _capacity = new_capacity;
            }
        }

        void clear() {
            for (size_t i = 0; i < _size; ++i) {
                allocator.destroy(data + i);
            }
            _size = 0;
        }


};

#endif // _VECTOR_H

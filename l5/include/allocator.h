#ifndef MY_ALLOCATOR_H
#define MY_ALLOCATOR_H

#include <list>


template <class T>
class Allocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        Allocator() noexcept {}

        T* allocate(size_t size) {
            T* new_pointer = static_cast<T*>(calloc(size, sizeof(T)));

            if (new_pointer) {
                used_pointers.push_back(new_pointer);
                return new_pointer;
            }

            throw std::bad_alloc();
        }

        void deallocate(T* block, size_t size) {
            used_pointers.remove(block);
            free(block);
        }

        ~Allocator() {
            for (T* block : used_pointers) {
                free(block);
            }
        }

    private:
        std::list<T*> used_pointers;
};


#endif // MY_ALLOCATOR_H
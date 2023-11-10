#ifndef MY_ALLOCATOR_H
#define MY_ALLOCATOR_H

#include <list>


template <class T>
class HmmAllocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        HmmAllocator() noexcept {}

        T* allocate(size_t size) {
            // std::cout << "Count = " << used_blocks.size() << '\n';
            // std::cout << "Alloc!\n";
            T* new_pointer = static_cast<T*>(calloc(size, sizeof(T)));

            if (new_pointer) {
                used_blocks.push_back(new_pointer);
               return new_pointer;
            }

            throw std::bad_alloc();
        }

        void deallocate(T* block, size_t size) {
            // std::cout << "Count = " << used_blocks.size() << '\n';
            // std::cout << "Dealloc!\n";

            used_blocks.remove(block);
            free(block);
        }

        ~HmmAllocator() {
            for (void* block : used_blocks) {
                free(block);
            }
        }

    private:
        std::list<T*> used_blocks;
};


template <class T, class U>
constexpr bool operator==(const HmmAllocator<T> &lhs, const HmmAllocator<U> &rhs) {
    return true;
}

template <class T, class U>
constexpr bool operator!=(const HmmAllocator<T> &lhs, const HmmAllocator<U> &rhs) {
    return false;
}


template <class T>
class StupidAllocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        StupidAllocator() noexcept {}

        T* allocate(size_t size) {
            // std::cout << "Count = " << used_blocks.size() << '\n';
            // std::cout << "Alloc!\n";
            T* new_pointer = static_cast<T*>(calloc(size, sizeof(T)));

            if (new_pointer) {
                used_blocks.push_back(new_pointer);
               return new_pointer;
            }

            throw std::bad_alloc();
        }

        void deallocate(T* block, size_t size) {
            // std::cout << "Count = " << used_blocks.size() << '\n';
            // std::cout << "Dealloc!\n";

            used_blocks.remove(block);
            free(block);
        }

        ~StupidAllocator() {
            for (void* block : used_blocks) {
                free(block);
            }
        }

    private:
        std::list<T*> used_blocks;
};


template <class T, class U>
constexpr bool operator==(const StupidAllocator<T> &lhs, const StupidAllocator<U> &rhs) {
    return true;
}

template <class T, class U>
constexpr bool operator!=(const StupidAllocator<T> &lhs, const StupidAllocator<U> &rhs) {
    return false;
}

#endif // MY_ALLOCATOR_H
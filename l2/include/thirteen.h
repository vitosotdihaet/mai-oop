#ifndef THIRTEEN_H
#define THIRTEEN_H

#include <map>
#include <string>
#include <stdint.h>
#include <ostream>


// Unsigned thirteen base numbers
class Thirteen {
    private:
        // values[0] is the right-most digit in a number
        unsigned char *values = nullptr;
        int64_t capacity = 0;

        void resize(int64_t new_capacity);

    public:
        const int64_t DEFAULT_CAPACITY = 2;
        const std::string ALPHABET = "0123456789ABC";
        const std::map<unsigned char, uint64_t> REV_ALPHABET = {
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9},
            {'A', 10},
            {'B', 11},
            {'C', 12}
        };

        // Constructors
        Thirteen();
        Thirteen(const size_t &n, unsigned char v = 0);
        Thirteen(const std::initializer_list<unsigned char>& l);
        Thirteen(const std::string& s);

        // Copy constructor
        Thirteen(const Thirteen& other);
        // Move constructor
        Thirteen(Thirteen&& other) noexcept;

        // Destructors
        virtual ~Thirteen() noexcept;

        // Operators
        // Copy assignment
        Thirteen& operator=(const Thirteen& other);
        // Move assignment
        Thirteen& operator=(Thirteen&& other) noexcept;

        bool operator==(Thirteen& other) noexcept;
        bool operator!=(Thirteen& other) noexcept;
        bool operator>(Thirteen& other) noexcept;
        bool operator<(Thirteen& other) noexcept;

        Thirteen operator+(Thirteen& other);
        Thirteen operator-(Thirteen& other);

        friend std::ostream& operator<<(std::ostream& os, const Thirteen& t);

        // Methods
        bool is_empty() noexcept;
};

#endif // THIRTEEN_H
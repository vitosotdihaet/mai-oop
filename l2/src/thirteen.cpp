#include <iostream>

#include "thirteen.h"

void Thirteen::push_num(short n) {
    int64_t i = 0;
    for (i = 0; i < this->capacity; ++i) { // should never end because of the for loop conditions
        if (this->values[i] == '\0') {
            break;
        }
    }

    this->values[i] = ALPHABET[n % 13];
    if (i + 1 == this->capacity) {
        this->resize(this->capacity * 2);
    }
    this->values[i + 1] = '\0';

    if (n > 12) {
        this->push_num(n / 13);
    }
}

void Thirteen::resize(int64_t new_capacity) {
    if (new_capacity < this->capacity) {
        throw std::invalid_argument("New capacity is smaller than the old one");
    } else if (new_capacity == this->capacity) {
        return;
    }

    unsigned char *new_values = new unsigned char[new_capacity];
    for (int64_t i = 0; i < this->capacity; ++i) {
        new_values[i] = this->values[i];
    }

    delete[] this->values;
    this->values = new_values;
    this->capacity = new_capacity;
}


Thirteen::Thirteen() {
    this->capacity = Thirteen::DEFAULT_CAPACITY;
    this->values = new unsigned char[this->capacity];

    this->values[0] = '0';
    this->values[1] = '\0';
}

Thirteen::Thirteen(const size_t &n, unsigned char v) {
    if (n == 0) { *this = Thirteen(); return; }

    this->capacity = (int64_t) n + 1;
    this->values = new unsigned char[this->capacity];

    std::fill_n(this->values, this->capacity - 1, v);
    this->values[this->capacity] = '\0';
}

Thirteen::Thirteen(const std::initializer_list<unsigned char>& l) {
    int64_t len = (int64_t) l.size();
    if (len == 0) { *this = Thirteen(); return; }

    this->capacity = len + 1;
    this->values = new unsigned char[this->capacity];

    for (int64_t i = 0; i < len; ++i) {
        this->values[i] = *(l.begin() + i);
    }

    this->values[this->capacity] = '\0';
    std::cout << "LAST VALUE IS " << this->values[this->capacity] << '\n';
}

Thirteen::Thirteen(const std::string& s) {

}


Thirteen::Thirteen(const Thirteen& other) {

}

Thirteen::Thirteen(Thirteen&& other) noexcept {

}


Thirteen::~Thirteen() noexcept {

}


// Copy
Thirteen& Thirteen::operator=(const Thirteen& other) {
    if (this == &other)
        return *this;

    if (this->capacity != other.capacity) {
        unsigned char *temp = new unsigned char[other.capacity];
        delete[] this->values;
        this->values = temp;
        this->capacity = other.capacity;
    }

    std::copy(other.values, other.values + other.capacity, this->values);
    return *this;
}

// Move
Thirteen& Thirteen::operator=(Thirteen&& other) noexcept {
    if (this == &other)
        return *this;

    delete[] this->values;
    this->values = other.values;
    other.values = nullptr;

    this->capacity = other.capacity;
    other.capacity = 0;

    return *this;
}

bool Thirteen::operator==(Thirteen& other) noexcept {
    int64_t min = std::min(other.capacity, this->capacity);
    for (int64_t i = 0; i < min; ++i) {
        if (this->values[i] != other.values[i]) return false;
    }

    if (min == other.capacity) {
        if (this->capacity > min) {
            if (this->values[min + 1] == '\0') {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        if (other.values[min + 1] == '\0') {
            return true;
        } else {
            return false;
        }
    }
}

bool Thirteen::operator!=(Thirteen& other) noexcept {
    return !(*this == other);
}

Thirteen Thirteen::operator+(Thirteen& other) {
    Thirteen temp;
    int64_t max = std::max(this->capacity, other.capacity);
    std::cout << "max = " << max << '\n';
    short a = 0, b = 0;

    for (int64_t i = 0; i < max; ++i) {
        a = b = 0;

        if (this->capacity > i) a = REV_ALPHABET.at(this->values[i]);
        if (other.capacity > i) b = REV_ALPHABET.at(other.values[i]);

        temp.push_num(a + b);
    }

    return temp;
}

std::ostream& operator<<(std::ostream& os, const Thirteen& t) {
    bool after_zero = false;

    for (int64_t i = 0; i < t.capacity; ++i) {
        if (t.values[i] == '\0') {
            for (int64_t j = 1; j <= i; ++i) {
      	        os << t.values[i - j];
            }
            break;
        }
    }

    return os;
}


bool Thirteen::is_empty() noexcept {
    if (this->capacity > 0) return this->values[0] == '\0';
    return true;
}
#include <iostream>
#include <cmath>

#include "thirteen.h"


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
    this->values[this->capacity - 1] = '\0';
}

Thirteen::Thirteen(const std::initializer_list<unsigned char>& l) {
    int64_t len = l.size();
    if (len == 0) { *this = Thirteen(); return; }

    this->capacity = len + 1;
    this->values = new unsigned char[this->capacity];

    for (int64_t i = 0; i < len; ++i) {
        this->values[i] = *(l.end() - 1 - i);
    }

    this->values[this->capacity - 1] = '\0';
}

Thirteen::Thirteen(const std::string& s) {
    int64_t len = s.size();
    if (len == 0) { *this = Thirteen(); return; }

    this->capacity = len + 1;
    this->values = new unsigned char[this->capacity];

    for (int64_t i = 0; i < len; ++i) {
        this->values[i] = s[len - 1 - i];
    }

    this->values[this->capacity - 1] = '\0';
}

// Copy constructor
Thirteen::Thirteen(const Thirteen& other) {
    *this = other;
}

// Move constructor
Thirteen::Thirteen(Thirteen&& other) noexcept {
    *this = std::move(other);
}


// Destructor
Thirteen::~Thirteen() noexcept {
    this->capacity = 0;
    if (this->values != nullptr) delete[] this->values;
}


// Copy assignment
Thirteen& Thirteen::operator=(const Thirteen& other) {
    if (this == &other)
        return *this;

    if (this->capacity != other.capacity) {
        unsigned char *temp = new unsigned char[other.capacity];
        if (this->values != nullptr) delete[] this->values;

        this->values = temp;
        this->capacity = other.capacity;
    }

    std::copy(other.values, other.values + other.capacity, this->values);
    return *this;
}

// Move assignment
Thirteen& Thirteen::operator=(Thirteen&& other) noexcept {
    if (this == &other)
        return *this;

    if (this->values != nullptr) delete[] this->values;
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

bool Thirteen::operator>(Thirteen& other) noexcept {
    int64_t max = std::max(this->capacity, other.capacity);

    for (int64_t i = 0; i < max; ++i) {
        if (i < this->capacity && i < other.capacity) {
            unsigned char c1 = this->values[i], c2 = other.values[i];
            if (c1 == '\0' && c2 != '\0') {
                return false;
            } else if (c1 != '\0' && c2 == '\0') {
                return true;
            } else if (c1 == '\0' && c2 == '\0') {
                for (int64_t j = i - 1; j >= 0; --j) {
                    if (this->values[j] > other.values[j]) return true;
                    else return false;
                }
            }
        } else if (i < this->capacity) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool Thirteen::operator<(Thirteen& other) noexcept {
    return other > *this;
}


Thirteen Thirteen::operator+(Thirteen& other) {
    Thirteen temp;

    int64_t max = std::max(this->capacity, other.capacity);
    uint64_t a = 0, b = 0, remainder = 0;

    for (int64_t i = 0; i < max - 1; ++i) {
        a = b = 0;

        if (i < this->capacity - 1) a = REV_ALPHABET.at(this->values[i]);
        if (i < other.capacity - 1) b = REV_ALPHABET.at(other.values[i]);

        if (remainder == 1) a += 1;

        remainder = (a + b) / 13;

        if (temp.capacity - 1 <= i) {
            temp.resize(temp.capacity * 2);
        }

        int64_t num = a + b;

        temp.values[i] = ALPHABET[num % 13];
        temp.values[i + 1] = ALPHABET[remainder];
    }

    if (remainder) temp.values[max] = '\0';
    else temp.values[max - 1] = '\0';

    return temp;
}

Thirteen Thirteen::operator-(Thirteen& other) {
    int64_t max = std::max(this->capacity, other.capacity);

    Thirteen temp = Thirteen(max, '\0');

    uint64_t a = 0, b = 0, remainder = 0;
    int64_t i = 0;

    for (i = 0; i < max - 1; ++i) {
        a = b = 0;

        if (i < this->capacity - 1) a = REV_ALPHABET.at(this->values[i]);
        if (i < other.capacity - 1) b = REV_ALPHABET.at(other.values[i]);
        
        if (remainder > 0) a -= remainder;

        int64_t num = a - b;

        if (num < 0) {
            if (this->values[i + 1] == '\0') {
                temp.values[0] = '0';
                temp.values[1] = '\0';
                break;
            }
            remainder = 1;
            temp.values[i] = ALPHABET[13 + num % 13];
        } else {
            remainder = 0;
            temp.values[i] = ALPHABET[num % 13];
        }
    }

    for (; i > 1; --i) { // i > 2 because we are not touching the first zero if it is present
        if (temp.values[i] == '\0' && temp.values[i - 1] == '0') temp.values[i - 1] = '\0';
    }

    return temp;
}


std::ostream& operator<<(std::ostream& os, const Thirteen& t) {
    for (int64_t i = 0; i < t.capacity; ++i) {
        if (t.values[i] == '\0') {
            for (int64_t j = 1; j <= i; ++j) {
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
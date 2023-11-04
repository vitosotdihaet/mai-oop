#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>


template <class T>
class Point {
    public:
        T x, y;

        Point(): x(0), y(0) {}

        Point(T x, T y): x(x), y(y) {}

        double distance(Point &other) {
            T dx = (other.x - this->x);
            T dy = (other.y - this->y);

            return std::sqrt(dx * dx + dy * dy);
        }

        friend std::istream& operator>>(std::istream& is, Point<T>& p) {
            is >> p.x >> p.y;
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, Point<T>& p) {
            os << p.x << ", " << p.y;
            return os;
        }

        bool operator==(Point& other) {
            return this->x == other.x && this->y == other.y;
        }

        bool operator!=(Point& other) {
            return !(*this == other);
        }
};

#endif // POINT_H
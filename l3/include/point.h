#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    public:
        double x;
        double y;

        Point();
        Point(double x, double y);

        double distance(Point &other);

        friend std::istream& operator>>(std::istream& is, Point& p);
        friend std::ostream& operator<<(std::ostream& os, Point& p);

        bool operator==(Point& other) {
            return this->x == other.x && this->y == other.y;
        }

        bool operator!=(Point& other) {
            return !(*this == other);
        }
};

#endif // POINT_H
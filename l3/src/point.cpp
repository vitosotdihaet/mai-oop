#include "point.h"

#include <cmath>


Point::Point(): x(0.), y(0.) {}

Point::Point(double x, double y): x(x), y(y) {}

double Point::distance(Point &other) {
    double dx = (other.x - this->x);
    double dy = (other.y - this->y);

    return std::sqrt(dx * dx + dy * dy);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << p.x << ", " << p.y;
    return os;
}
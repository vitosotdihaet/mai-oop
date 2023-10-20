#include "rect.h"

Rectangle::Rectangle() {
    this->points = vector(this->point_count(), Point());
}

Rectangle::operator double() const {
    Point p1 = points[0], p2 = points[1], p3 = points[2], p4 = points[3];
    double a = p1.distance(p2);
    double b = p1.distance(p3);
    double c = p1.distance(p4);

    double d1 = std::max(a, b);
    double d2 = std::max(d1, c);

    if (d2 == a) return b * c;
    if (d2 == b) return a * c;
    return a * b;
}


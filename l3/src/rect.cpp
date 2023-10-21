#include "rect.h"

#define EPS 1e-9

Rectangle::Rectangle() {
    this->points = std::vector(this->point_count(), Point());
}

std::istream& operator>>(std::istream& is, Rectangle& r) {
    for (int i = 0; i < r.point_count(); ++i) {
        is >> r.points[i];
    }

    Point p1 = r.points[0];
    Point p2 = r.points[1];
    Point p3 = r.points[2];
    Point p4 = r.points[3];

    double m12 = (double) (p2.y - p1.y)/(p2.x - p1.x);
    double m23 = (double) (p3.y - p2.y)/(p3.x - p2.x);
    double m14 = (double) (p4.y - p1.y)/(p4.x - p1.x);
    double m34 = (double) (p4.y - p3.y)/(p4.x - p3.x);

    if (!(abs(m12 * m23 + 1) < EPS && abs(m14 * m34 + 1) < EPS)) {
        std::cout << "Bad coordinates! It's not a rectangle!\n";
        for (int i = 0; i < r.point_count(); ++i) { r.points[i] = Point(0, 0); }
    }

    return is;
}

Rectangle::operator double() const {
    Point p1 = points[0], p2 = points[1], p3 = points[2];
    double a = p1.distance(p2);
    double b = p2.distance(p3);

    return a * b;
}

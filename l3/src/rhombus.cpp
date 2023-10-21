#include "rhombus.h"

Rhombus::Rhombus() {
    this->points = std::vector(this->point_count(), Point());
}

#define EPS 1e-9

std::istream& operator>>(std::istream& is, Rhombus& r)  {
    for (int i = 0; i < r.point_count(); ++i) {
        is >> r.points[i];
    }

    bool is_rhombus = false;

    Point p1 = r.points[0];
    Point p2 = r.points[1];
    Point p3 = r.points[2];
    Point p4 = r.points[3];

    double d14 = p1.distance(p4);
    double d12 = p1.distance(p2);
    double d34 = p3.distance(p4);
    double d32 = p3.distance(p2);

    if (abs(d14 - d32) < EPS && abs(d12 - d34) < EPS) {
        double m13 = (double) (p3.y - p1.y)/(p3.x - p1.x);
        double m24 = (double) (p4.y - p2.y)/(p4.x - p2.x);

        if (abs(m13 * m24 + 1) < EPS) is_rhombus = true;
    }

    if (!is_rhombus) {
        std::cout << "Bad coordinates! It's not a rhombus!\n";
        for (int i = 0; i < r.point_count(); ++i) { r.points[i] = Point(0, 0); }
    }

    return is;
}

Rhombus::operator double() const {
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


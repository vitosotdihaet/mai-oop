#include "rhombus.h"

Rhombus::Rhombus() {
    this->points = std::vector(this->point_count(), Point());
}

std::istream& operator>>(std::istream& is, Rhombus& r)  {
    for (int i = 0; i < r.point_count(); ++i) {
        is >> r.points[i];
    } return is;

    std::pair<double, double> p1 = r.points[0].pair();
    std::pair<double, double> p2 = r.points[0].pair();
    std::pair<double, double> p3 = r.points[0].pair();
    std::pair<double, double> p4 = r.points[0].pair();

    double x1 = p1.first,  x2 = p2.first,  x3 = p3.first,  x4 = p4.first;
    double y1 = p1.second, y2 = p2.second, y3 = p3.second, y4 = p4.second;

    // Check if the opposite sides of the rectangle are equal in length
    // if (!(
    //         (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) == (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4) &&
    //         (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) == (x4-x1)*(x4-x1) + (y4-y1)*(y4-y1)
    //     )
    // ) {
    //     std::cout << "Bad coordinates! It's not a rhombus!\n";
    //     for (int i = 0; i < r.point_count(); ++i) { r.points[i] = Point(0, 0); }
    // }

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


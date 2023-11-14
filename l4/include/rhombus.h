#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

#define EPS 1e-9

template <class T>
class Rhombus: public Figure<T> {
    public:
        using Figure<T>::Figure;

        Rhombus();
        Rhombus(const Rhombus<T>& r);

        operator double() const override;
        size_t point_count() const override { return 4; };

        template <class Y>
        friend std::istream& operator>>(std::istream& is, Rhombus<Y>& r);
};

template <class T>
Rhombus<T>::Rhombus() {
    this->points = std::vector(this->point_count(), Point<T>());
}

template <class T>
Rhombus<T>::Rhombus(const Rhombus<T>& r) {
    for (uint64_t i = 0; i < r.points.size(); ++i) {
        this->points.push_back(r.points[i]);
    }
}


template <class T>
std::istream& operator>>(std::istream& is, Rhombus<T>& r)  {
    for (int i = 0; i < r.point_count(); ++i) {
        is >> r.points[i];
    }

    bool is_rhombus = false;

    Point<T> p1 = r.points[0];
    Point<T> p2 = r.points[1];
    Point<T> p3 = r.points[2];
    Point<T> p4 = r.points[3];

    double d14 = p1.distance(p4);
    double d12 = p1.distance(p2);
    double d34 = p3.distance(p4);
    double d32 = p3.distance(p2);

    if (abs(d14 - d32) < EPS && abs(d12 - d34) < EPS, abs(d14 - d12) < EPS) {
        double m13 = (double) (p3.y - p1.y)/(p3.x - p1.x);
        double m24 = (double) (p4.y - p2.y)/(p4.x - p2.x);

        if (abs(m13 * m24 + 1) < EPS) is_rhombus = true;
    }

    if (!is_rhombus) {
        std::cout << "Bad coordinates! It's not a rhombus!\n";
        for (int i = 0; i < r.point_count(); ++i) { r.points[i] = Point<T>(0, 0); }
    }

    return is;
}

template <class T>
Rhombus<T>::operator double() const {
    Point<T> p1 = this->points[0], p2 = this->points[1], p3 = this->points[2], p4 = this->points[3];
    double a = p1.distance(p3);
    double b = p2.distance(p4);

    return a * b / 2.;
}



#endif // RHOMBUS_H
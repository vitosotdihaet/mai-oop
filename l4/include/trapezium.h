#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "figure.h"

#define EPS 1e-9


template <class T>
class Trapezium: public Figure<T> {
    public:
        Trapezium();
        operator double() const;
        size_t point_count() const { return 4; };

        template <class Y>
        friend std::istream& operator>>(std::istream& is, Trapezium<Y>& r);
};

template <class T>
Trapezium<T>::Trapezium() {
    this->points = std::vector(this->point_count(), Point<T>());
}

template <class T>
std::istream& operator>>(std::istream& is, Trapezium<T>& r) {
    for (int i = 0; i < r.point_count(); ++i) {
        is >> r.points[i];
    }

    Point<T> p1 = r.points[0];
    Point<T> p2 = r.points[1];
    Point<T> p3 = r.points[2];
    Point<T> p4 = r.points[3];

    double m12 = (double) (p2.y - p1.y)/(p2.x - p1.x);
    double m23 = (double) (p3.y - p2.y)/(p3.x - p2.x);
    double m14 = (double) (p4.y - p1.y)/(p4.x - p1.x);
    double m34 = (double) (p4.y - p3.y)/(p4.x - p3.x);

    if (!(m12 == m34 || m23 == m14)) {
        std::cout << "Bad coordinates! It's not a trapezium!\n";
        for (int i = 0; i < r.point_count(); ++i) { r.points[i] = Point<T>(0, 0); }
    }

    return is;
}

template <class T>
Trapezium<T>::operator double() const {
    Point<T> p1 = this->points[0], p2 = this->points[1], p3 = this->points[2], p4 = this->points[3];

    return abs(0.5 * (p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p1.y -
                      p2.x * p1.y - p3.x * p2.y - p4.x * p3.y - p1.x * p4.y));
}


#endif // TRAPEZIUM_H
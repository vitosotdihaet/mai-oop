#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

#define EPS 1e-9

template <class T>
class Rectangle: public Figure<T> {
    public:
        using Figure<T>::Figure;

        Rectangle();
        Rectangle(const Rectangle<T>& t);

        operator double() const override;
        size_t point_count() const override { return 4; }

        template <class Y>
        friend std::istream& operator>>(std::istream& is, Rectangle<Y>& r);
};

template <class T>
Rectangle<T>::Rectangle() {
    this->points = std::vector(this->point_count(), Point<T>());
}

template <class T>
Rectangle<T>::Rectangle(const Rectangle<T>& t) {
    for (uint64_t i = 0; i < t.points.size(); ++i) {
        this->points.push_back(t.points[i]);
    }
}


template <class T>
std::istream& operator>>(std::istream& is, Rectangle<T>& r) {
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

    if (!(abs(m12 * m23 + 1) < EPS && abs(m14 * m34 + 1) < EPS)) {
        std::cout << "Bad coordinates! It's not a rectangle!\n";
        for (int i = 0; i < r.point_count(); ++i) { r.points[i] = Point<T>(0, 0); }
    }

    return is;
}

template <class T>
Rectangle<T>::operator double() const {
    Point<T> p1 = this->points[0], p2 = this->points[1], p3 = this->points[2];
    double a = p1.distance(p2);
    double b = p2.distance(p3);

    return a * b;
}


#endif // RECTANGLE_H
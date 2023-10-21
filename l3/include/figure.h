#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

#include "point.h"


class Figure {
    public:
        virtual size_t point_count() const { return 0; };

        operator double() const { return 0; };

        friend std::ostream& operator<<(std::ostream& os, Figure &f) {
            for (int i = 0; i < f.point_count(); ++i) {
                os << f.points[i] << "; ";
            } os << '\n';
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Figure& f) { return is; };

        virtual ~Figure() noexcept {};

        // Copy assignment
        Figure& operator=(const Figure& other) {
            if (this == &other)
                return *this;

            this->points = std::vector(other.point_count(), Point());
            for (int i = 0; i < other.point_count(); ++i) {
                this->points[i] = other.points[i];
            }

            return *this;
        }

        // Move assignment
        Figure& operator=(Figure&& other) noexcept {
            if (this == &other) return *this;
            this->points = std::move(other.points);
            return *this;
        }

        bool operator==(Figure& other) noexcept {
            if (this->point_count() != other.point_count()) return false;
            for (int i = 0; i < this->point_count(); ++i) {
                if (this->points[i] != other.points[i]) return false;
            }
            return true;
        }

    protected:
        std::vector<Point> points;
};


#endif // FIGURE_H
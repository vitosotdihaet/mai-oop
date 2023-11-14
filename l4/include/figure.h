#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

#include "point.h"


template <class T>
class Figure {
    public:
        virtual size_t point_count() const { return 0; };

        virtual operator double() const { return 0; };

        friend std::ostream& operator<<(std::ostream& os, Figure<T> &f) {
            for (int i = 0; i < f.point_count(); ++i) {
                os << f.points[i] << "; ";
            } os << "\b\b \b";
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Figure<T>& f) {
            for (int i = 0; i < f.point_count(); ++i) {
                is >> f.points[i];
            }
            return is;
        };

        virtual ~Figure() noexcept {};
        
        // Copy assignment
        virtual Figure<T>& operator=(const Figure<T>& other) {
            if (this == &other)
                return *this;

            this->points = std::vector(other.point_count(), Point<T>());
            for (int i = 0; i < other.point_count(); ++i) {
                this->points[i] = other.points[i];
            }

            return *this;
        }

        // Move assignment
        virtual Figure<T>& operator=(Figure<T>&& other) noexcept {
            if (this == &other) return *this;
            this->points = std::move(other.points);
            return *this;
        }

        Figure() noexcept {
            points = std::vector(point_count(), Point<T>());
        }

        Figure(const Figure<T>& f) {
            *this = f;
        }
        
        Figure(const Figure<T>&& f) {
            *this = std::move(f);
        }

        Figure(std::vector<Point<T>> p) {
            points.clear();
            for (size_t i = 0; i < p.size(); ++i) {
                points.push_back(p[i]);
            }
        }

        virtual bool operator==(Figure<T>& other) noexcept {
            if (this->point_count() != other.point_count()) return false;
            for (int i = 0; i < this->point_count(); ++i) {
                if (this->points[i] != other.points[i]) return false;
            }
            return true;
        }

    protected:
        std::vector<Point<T>> points;
};


#endif // FIGURE_H
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

#include "point.h"


class Figure {
    public:
        virtual size_t point_count() { return 0; };

        friend std::istream& operator>>(std::istream& is, Figure &f) {
            std::cout << "Input for " << f.point_count() << " points!\n";
            for (int i = 0; i < f.point_count(); ++i) {
                is >> f.points[i];
            } return is;
        };

        friend std::ostream& operator<<(std::ostream& os, Figure &f) {
            for (int i = 0; i < f.point_count(); ++i) {
                os << f.points[i] << "; ";
            } os << '\n';
            return os;
        }

        virtual ~Figure() noexcept {};

    protected:
        std::vector<Point> points;
};


#endif // FIGURE_H
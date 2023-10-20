#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"


class Rectangle: public Figure {
    public:
        Rectangle();
        operator double() const;
        size_t point_count() { return 4; };

        friend std::istream& operator>>(std::istream& is, Rectangle& r);
};

#endif // RECTANGLE_H
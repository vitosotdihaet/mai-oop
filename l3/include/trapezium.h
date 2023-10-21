#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "figure.h"


class Trapezium: public Figure {
    public:
        Trapezium();
        operator double() const;
        size_t point_count() const { return 4; };

        friend std::istream& operator>>(std::istream& is, Trapezium& r);
};

#endif // TRAPEZIUM_H
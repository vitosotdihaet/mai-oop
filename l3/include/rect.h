#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "figure.h"
#include "point.h"

using namespace std;

class Rectangle: public Figure {
    public:
        Rectangle();
        operator double() const;
        size_t point_count() { return 4; };
};

#endif
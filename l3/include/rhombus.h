#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"


class Rhombus: public Figure {
    public:
        Rhombus();
        operator double() const;
        size_t point_count() const { return 4; };

        friend std::istream& operator>>(std::istream& is, Rhombus& r);
};

#endif // RHOMBUS_H
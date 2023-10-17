#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>


class Figure {
    friend std::ostream& operator<<(std::ostream& os, const Figure& t);
};

#endif FIGURE_H
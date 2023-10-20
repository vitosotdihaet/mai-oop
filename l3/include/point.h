#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    public:
        Point();
        Point(double x, double y);

        double distance(Point &other);

        std::pair<double, double> pair() { return std::pair(x_, y_); };

        friend std::istream& operator>>(std::istream& is, Point& p);
        friend std::ostream& operator<<(std::ostream& os, Point& p);

    private:
        double x_;
        double y_;
};

#endif // POINT_H
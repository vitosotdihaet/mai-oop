#include <iostream>

#include "rect.h"
#include "trapezium.h"
#include "rhombus.h"


int main() {
    int n = 0, i = 0;
    std::cout << "How many figures do you want to store? ";
    std::cin >> n;

    Figure* figures = new Figure[n];
    double s = 0;

    for (int i = 0; i < n; ++i) {
        std::cout << "Select a figure to append (" << i + 1 << '/' << n << "):\n";
        std::cout << "\t1) Rectangle\n";
        std::cout << "\t2) Trapezium\n";
        std::cout << "\t3) Rhombus\n";

        int choice;
        std::cin >> choice;

        std::cout << "Enter 4 points (8 numbers):\n";

        if (choice == 1) {
            Rectangle r;
            std::cin >> r;
            std::cout << "The rectangle you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';
            s += r;

            figures[i] = std::move(r);
        } else if (choice == 2) {
            Trapezium t;
            std::cin >> t;
            std::cout << "The trapezium you input was " << t << '\n';
            std::cout << "Its area = " << (double) t << '\n';
            s += t;

            figures[i] = std::move(t);
        } else if (choice == 3) {
            Rhombus r;
            std::cin >> r;
            std::cout << "The rhombus you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';
            s += r;

            figures[i] = std::move(r);
        }
    }

    std::cout << "The total area of all the figures = " << s << '\n';

    delete figures;

    return 0;
}
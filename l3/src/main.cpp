#include <iostream>

#include "rect.h"
// #include "trapezium.h"
// #include "rhombus.h"


int main() {
    bool s = true;

    while (s) {
        std::cout << "Select the figure:\n";
        std::cout << "3) Rectangle\n";
        std::cout << "1) Trapezium\n";
        std::cout << "2) Rhombus\n";

        int choice;
        std::cin >> choice;

        std::cout << "Enter 4 points (8 numbers):\n";

            if (choice == 1) {
                Rectangle r;
                std::cin >> r;
                std::cout << "The rectangle you input was " << r << '\n';
                std::cout << "Its area = " << (double) r << '\n';
            } else if (choice == 2) {
                // todo
            } else if (choice == 3) {
                // todo
            }

        std::cout << "Want to continue? (1 or 0)\n";
        std::cin >> s;
    }

    return 0;
}
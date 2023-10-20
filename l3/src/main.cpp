#include <iostream>

#include "rect.h"
#include "trapezium.h"
#include "rhombus.h"


int main() {
    int n = 0;
    std::cout << "How many figures do you want to store? ";
    std::cin >> n;

    Figure* figures = new Figure[n];

    bool s = true;

    while (s) {
        std::cout << "Select the figure to append:\n";
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
        } else if (choice == 2) {
            Trapezium r;
            std::cin >> r;
            std::cout << "The trapezium you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';
        } else if (choice == 3) {
            Rhombus r;
            std::cin >> r;
            std::cout << "The rhombus you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';
        }

        std::cout << "Do want to continue? (0/1)\n";
        std::cin >> s;
    }

    delete(figures);

    return 0;
}
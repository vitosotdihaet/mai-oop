#include <iostream>

#include "rect.h"
#include "trapezium.h"
#include "rhombus.h"
#include "array.h"

#define TYPE double


int main() {
    int n = 0, i = 0;
    std::cout << "How many figures do you want to store? ";
    std::cin >> n;

    Array<std::shared_ptr<Figure<TYPE>>> figures(n);
    double s = 0;

    for (int i = 0; i < n; ++i) {
        std::cout << "Select a command (" << i << "/" << n << " figures):\n";
        std::cout << "\t1) Append rectangle\n";
        std::cout << "\t2) Append trapezium\n";
        std::cout << "\t3) Append rhombus\n";
        std::cout << "\t4) Delete a figure at index\n";
        std::cout << "\t5) Print whole array\n";

        int choice;
        std::cin >> choice;

        std::cout << "Enter 4 points (8 numbers):\n";

        if (choice == 1) {
            Rectangle<TYPE> r;
            std::cin >> r;
            std::cout << "The rectangle you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';
            s += r;

            figures[i] = std::make_shared<Rectangle<TYPE>>(r);
        } else if (choice == 2) {
            Trapezium<TYPE> t;
            std::cin >> t;
            std::cout << "The trapezium you input was " << t << '\n';
            std::cout << "Its area = " << (double) t << '\n';
            s += t;

            figures[i] = std::make_shared<Trapezium<TYPE>>(t);
        } else if (choice == 3) {
            Rhombus<TYPE> r;
            std::cin >> r;
            std::cout << "The rhombus you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';
            s += r;

            figures[i] = std::make_shared<Rhombus<TYPE>>(r);
        } else if (choice == 4) {
            int index = 0;
            std::cout << "Input an index of an element you want to delete: ";
            std::cin >> index;

            figures.remove(index);
            --i;
            --i;
        } else if (choice == 5) {
            for (int i = 0; i < figures.get_size(); ++i) {
                std::cout << i << ": " << *figures[i] << '\n';
            }
            --i;
        }
    }

    std::cout << "The total area of all the figures = " << s << '\n';

    return 0;
}
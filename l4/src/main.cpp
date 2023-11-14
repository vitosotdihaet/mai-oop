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
        std::cout << "\t1) Append a rectangle\n";
        std::cout << "\t2) Append a trapezium\n";
        std::cout << "\t3) Append a rhombus\n";
        std::cout << "\t4) Delete a figure at index\n";
        std::cout << "\t5) Print whole array\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter 4 points (8 numbers):\n";
            Rectangle<TYPE> r;
            std::cout << "Current point count = " << r.point_count() << '\n';
            std::cin >> r;
            std::cout << "The rectangle you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';

            figures[i] = std::make_shared<Rectangle<TYPE>>(r);
        } else if (choice == 2) {
            std::cout << "Enter 4 points (8 numbers):\n";
            Trapezium<TYPE> t;
            std::cin >> t;
            std::cout << "The trapezium you input was " << t << '\n';
            std::cout << "Its area = " << (double) t << '\n';

            figures[i] = std::make_shared<Trapezium<TYPE>>(t);
        } else if (choice == 3) {
            std::cout << "Enter 4 points (8 numbers):\n";
            Rhombus<TYPE> r;
            std::cin >> r;
            std::cout << "The rhombus you input was " << r << '\n';
            std::cout << "Its area = " << (double) r << '\n';

            figures[i] = std::make_shared<Rhombus<TYPE>>(r);
        } else if (choice == 4) {
            int index = 0;
            std::cout << "Input an index of an element you want to delete: ";
            std::cin >> index;

            figures.remove(index);
            --i;
            --i;
        } else if (choice == 5) {
            for (int j = 0; j < figures.get_size(); ++j) {
                if (figures[j]) std::cout << j << ": " << *(figures[j]) << '\n';
            }
            --i;
        }
    }

    std::cout << "The total area of all the figures = " << figures.area() << '\n';

    return 0;
}
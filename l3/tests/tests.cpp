#include <gtest/gtest.h>
#include "rect.h"


TEST(Initializations, All) {
    Rectangle r;
    std::cout << "Input a rectangle by its points:\n";
    std::cin >> r;
    // std::cout << r << '\n';
    std::cout << "Area of this rectangle = " << (double) r << '\n';

    
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

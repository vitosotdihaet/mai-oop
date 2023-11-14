#include <gtest/gtest.h>

#include "rect.h"
#include "rhombus.h"
#include "trapezium.h"
#include "point.h"

#include <vector>


TEST(Compare, All) {
    std::vector<Point<int>> points = { Point<int>(0, 0), Point<int>(0, 1), Point<int>(1, 1), Point<int>(0, 1) };
    Rectangle<int> r1(points);
    Rectangle<int> r2(r1);

    ASSERT_TRUE(r1 == r2);
    ASSERT_TRUE((double) r1 == 1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

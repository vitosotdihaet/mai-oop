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
}

TEST(Square, All) {
    std::vector<Point<float>> points_1 = { Point<float>(0., 0.), Point<float>(0., 1.), Point<float>(1., 1.), Point<float>(0., 1.) };
    Rectangle<float> r1(points_1);
    ASSERT_TRUE((double) r1 == 1);

    std::vector<Point<float>> points_2 = { Point<float>(0., 0.), Point<float>(3., 0.), Point<float>(2., 1.), Point<float>(1., 1.) };
    Trapezium<float> t1(points_2);
    ASSERT_TRUE((double) t1 == 2);

    std::vector<Point<float>> points_3 = { Point<float>(0., 0.), Point<float>(1., 1.), Point<float>(0., 2.), Point<float>(-1., 1.) };
    Trapezium<float> rh1(points_3);
    ASSERT_TRUE((double) rh1 == 2);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

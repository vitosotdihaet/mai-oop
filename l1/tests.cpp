#include <gtest/gtest.h>
#include "task.hpp"


TEST(ClosestPair, FromLab) {
    ASSERT_TRUE(closest_pair_tonum(10) == std::pair(5, 4));
    ASSERT_TRUE(closest_pair_tonum(30) == std::pair(29, 20));
    ASSERT_TRUE(closest_pair_tonum(50) == std::pair(45, 36));
}

TEST(ClosestPair, Custom) {
    ASSERT_TRUE(closest_pair_tonum(100) == std::pair(97, 72));
    ASSERT_TRUE(closest_pair_tonum(500) == std::pair(493, 468));
}

TEST(ClosestPair, Borderline) {
    ASSERT_TRUE(closest_pair_tonum(0) == std::pair(0, 0));
    ASSERT_TRUE(closest_pair_tonum(-1) == std::pair(0, 0));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

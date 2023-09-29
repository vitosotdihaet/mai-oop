#include <gtest/gtest.h>
#include "thirteen.h"


// TEST(ClosestPair, Borderline) {
//     ASSERT_TRUE(closest_pair_tonum(0) == std::pair(0, 0));
//     ASSERT_TRUE(closest_pair_tonum(-1) == std::pair(0, 0));
// }


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

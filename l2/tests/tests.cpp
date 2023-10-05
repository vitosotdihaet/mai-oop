#include <gtest/gtest.h>
#include "thirteen.h"


TEST(Initializations, All) {
    Thirteen t1 = { 'C', 'A', '3' };
    Thirteen t2 = Thirteen(3, 'A');
    Thirteen t3 = Thirteen();
    Thirteen t4 = Thirteen(0, 'A');
    ASSERT_TRUE(t3 == t4);

    t4 = t2;
    ASSERT_TRUE(t4 == t2);

    t2 = std::move(t1);
    ASSERT_TRUE(t1.is_empty());
    ASSERT_TRUE(t4 != t2);

    Thirteen t5 = Thirteen(t4);
    Thirteen t6 = Thirteen(std::move(t4));
    ASSERT_TRUE(t4.is_empty());
    ASSERT_TRUE(t5 == t6);
}

TEST(Addition, All) {
    Thirteen t1 = { '8', 'A' };
    Thirteen t2 = { 'A', 'B' };

    Thirteen t3 = std::string("168");
    Thirteen t4 = t1 + t2;
    ASSERT_TRUE(t4 == t3);

    Thirteen ta = { 'A' };
    t1 = { '1' };
    Thirteen tb = { 'B' };
    ASSERT_TRUE(ta + t1 == tb);
}

TEST(Subtraction, All) {
    Thirteen t1 = { 'A', 'B' };
    Thirteen t2 = { 'A', 'A' };
    Thirteen t3 = { '1' };

    ASSERT_TRUE(t1 - t2 == t3);

    t1 = { 'B', 'A' };
    t2 = { 'A', 'B' };
    t3 = { 'C' };
    ASSERT_TRUE(t1 - t2 == t3);

    t1 = { '8', 'A' };
    t2 = { 'A', 'B' };
    t3 = Thirteen();

    ASSERT_TRUE(t1 - t2 == t3);

    t1 = { '5' };
    t2 = { '2' };
    t3 = { '3' };
    ASSERT_TRUE(t1 - t2 == t3);
}

TEST(Comparison, All) {
    Thirteen t1 = { '8' };
    Thirteen t2 = { 'A' };

    ASSERT_TRUE(t2 > t1);

    t1 = { '8', 'A' };
    t2 = { 'A', 'B' };

    ASSERT_TRUE(t2 > t1);

    Thirteen t3 = std::string("168");
    ASSERT_TRUE(t3 > t1);
    ASSERT_TRUE(t1 < t3);

    ASSERT_TRUE(!(t1 > t1));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

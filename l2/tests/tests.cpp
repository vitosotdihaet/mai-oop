#include <gtest/gtest.h>
#include "thirteen.h"


TEST(Thirteen, Initializations) {
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

TEST(Thirteen, Addition) {
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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

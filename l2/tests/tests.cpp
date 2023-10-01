#include <gtest/gtest.h>
#include "thirteen.h"


TEST(Thirteen, Initializations) {
    std::cout << "FIRST TEST\n";
    Thirteen t1 = { 'A', '3', 'C' };
    std::cout << "t1 = " << t1 << '\n';
    Thirteen t2 = Thirteen(3, 'A');
    Thirteen t3 = Thirteen();
    Thirteen t4 = Thirteen(0, 'A');
    ASSERT_TRUE(t3 == t4);

    std::cout << "SECOND TEST\n";
    t4 = t2;
    ASSERT_TRUE(t4 == t2);

    std::cout << "THIRD TEST\n";
    t2 = std::move(t1);
    ASSERT_TRUE(t1.is_empty());
    std::cout << "FOURTH TEST\n";
    ASSERT_TRUE(t4 != t2);

    std::cout << "FIFTH TEST\n";
    t1 = { 'A' };
    t2 = t1;

    t3 = { '7', '1' };
    std::cout << "t1 = " << t1 << "; t2 = " << t2 << "; t3 = " << t3 << ';' << '\n'; 

    ASSERT_TRUE(t1 + t2 == t3);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>


#include <vector>

#include "vector.h"
#include "allocator.h"


TEST(Allocator, std_vector) {
    std::vector<int, Allocator<int>> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(10);
    v1.push_back(-1);
    v1.push_back(10);
    v1.push_back(10);
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();

    std::vector<int> v2 = { 1, 2, 3, 4, 5, 10 };

    ASSERT_TRUE(v1.size() == v2.size());

    for (int i = 0; i < v2.size(); ++i) {
        ASSERT_TRUE(v1[i] == v2[i]);
    }
}

TEST(Allocator, std_map) {
    std::map<int, int, std::less<int>, Allocator<std::pair<int, int>>> m1;

    int64_t counter = 1;
    m1.insert(std::pair<int, int>(0, 0));
    for (int64_t i = 1; i < 10; ++i) {
        counter *= i;
        m1.insert(std::pair<int, int>(i, counter));
    }

    m1.erase(4);
    m1.erase(5);

    std::map<int, int> m2;

    counter = 1;
    m2.insert(std::pair<int, int>(0, 0));
    for (int64_t i = 1; i < 10; ++i) {
        counter *= i;
        m2.insert(std::pair<int, int>(i, counter));
    }

    m2.erase(4);
    m2.erase(5);

    for (int i = 0; i < 10; ++i) {
        ASSERT_TRUE(m1[i] == m2[i]);
    }
}

TEST(Allocator, Vector) {
    Vector<int, Allocator<int>> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(10);
    v1.push_back(-1);
    v1.push_back(10);
    v1.push_back(10);
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();

    std::vector<int> v2 = { 1, 2, 3, 4, 5, 10 };

    ASSERT_TRUE(v1.size() == v2.size());

    for (int i = 0; i < v2.size(); ++i) {
        ASSERT_TRUE(v1[i] == v2[i]);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
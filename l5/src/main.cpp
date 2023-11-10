#include <iostream>
#include <vector>
#include <map>

#include "allocator.h"


int main() {
    std::vector<int, HmmAllocator<int>> v;
    v.reserve(10);

    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(10);
    v.push_back(-1);
    v.push_back(10);
    v.push_back(10);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    for (auto e: v) {
        std::cout << e << ' ';
    } std::cout << '\n';

    std::map<int, int, std::less<int>, HmmAllocator<std::pair<int, int>>> m;

    // m.reserve?

    int64_t counter = 1;
    m.insert(std::pair<int, int>(0, 0));
    for (int64_t i = 1; i < 10; ++i) {
        counter *= i;
        m.insert(std::pair<int, int>(i, counter));
    }

    for (auto e: m) {
        std::cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}
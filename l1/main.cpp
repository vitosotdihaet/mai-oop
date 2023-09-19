#include <iostream>
#include "task.hpp"


int main() {
    int limit = 0;
    std::cin >> limit;

    std::pair<int, int> p = closest_pair_tonum(limit);
    std::cout << p.first << '\n';
    std::cout << p.second << '\n';

    return 0;
}
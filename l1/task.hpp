#include <math.h>

bool quads(int a, int b) {
    return std::sqrt(a + b) == trunc(std::sqrt(a + b)) &&
           std::sqrt(a - b) == trunc(std::sqrt(a - b));
}

std::pair<int, int> closest_pair_tonum(int upper_limit) {
    for (int i = upper_limit - 1; i > 0; --i) {
        for (int j = i - 1; j > 0; --j) {
            if (quads(i, j)) {
                return std::pair<int, int>(i, j);
            }
        }
    }

    return std::pair<int, int>(0, 0);
}

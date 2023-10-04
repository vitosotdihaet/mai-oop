#include <stdint.h>


uint64_t pow(uint64_t n, uint64_t e) {
    uint64_t t = 1;

    for (int64_t _ = 0; _ < e; ++_) {
        t *= n;
    }

    return t;
}
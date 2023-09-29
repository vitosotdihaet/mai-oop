#include "thirteen.h"

// Unsigned thirteen base numbers
class Thirteen {
    private:
        // values[0] is the right-most digit in a number
        unsigned char *values;
        int64_t capacity;
};
#include "stric.h"
std::size_t count_calls()
{
    // static std::size_t ctr = 0;
    static std::size_t ctr = 0;
    return ++ctr;
}


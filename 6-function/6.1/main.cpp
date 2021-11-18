#include "stric.h"
int main()
{
    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << count_calls() << std::endl;
    }
    return 0;
}
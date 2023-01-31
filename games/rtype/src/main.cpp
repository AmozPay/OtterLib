// #include "OtterGraphic.hpp"
// #include "OtterNetwork.hpp"

#include "OtterCore.hpp"
#include "OtterGraphic.hpp"

#include <iostream>

int main(int ac, char** av)
{
#ifdef TARGET_CLIENT
    std::cout << "CLIENT" << std::endl;
#elif TARGET_SERVER
    std::cout << "SERVER" << std::endl;
#endif

    return 0;
}
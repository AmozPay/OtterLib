#include "OtterGraphic.hpp"
#include "OtterNetwork.hpp"

#include <iostream>

int main(int ac, char** av)
{
#ifdef TARGET_CLIENT
    std::cout << "CLIENT" << std::endl;
#elif TARGET_SERVER
    std::cout << "SERVER" << std::endl;
#endif
    Otter::Network::print_hello();
    Otter::Graphic::start();
    Otter::Graphic::end();
    return 0;
}

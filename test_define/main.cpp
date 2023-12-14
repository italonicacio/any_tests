
#include <iostream>


int main()
{

#ifdef ON
    std::cout << "On if" << std::endl;

#else
    std::cout << "Off if" << std::endl;
#endif


    return 0;
}

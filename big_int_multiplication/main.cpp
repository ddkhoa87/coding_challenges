#include "source.hpp"

int main()
{
    BigInt a{15}, b{10};
    a *= b;

    std::cout << a << std::endl;  // the overloaded << does not accept std::endl internally
    
    return 0;
}
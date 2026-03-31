#include <iostream>
#include "rational.hpp"

int main()
{
    rational<int> a(3, 9);
    rational<int> b(2, -3);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "a / b = " << a / b << "\n";

    return 0;
}
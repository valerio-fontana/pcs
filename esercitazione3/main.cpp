#include <iostream>
#include "rational.hpp"

using namespace std;

int main()
{
    rational<int> a(3, 9);
    rational<int> b(2, -3);

    cout << "Operatori finiti" << "\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "\n";
    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    cout << "a / b = " << a / b << "\n";
    cout << "\n";

    rational<int> c(4, 0);
    rational<int> d(8, -3);

    cout << "Operatore infinito e operatore finito" << "\n";
    cout << "c = " << c << "\n";
    cout << "d = " << d << "\n";
    cout << "\n";
    cout << "c + d = " << c + d << "\n";
    cout << "c - d = " << c - d << "\n";
    cout << "c * d = " << c * d << "\n";
    cout << "c / d = " << c / d << "\n";
    cout << "\n";

    rational<int> e(4, 0);
    rational<int> f(-5, 0);

    cout << "Operatori infiniti" << "\n";
    cout << "e = " << e << "\n";
    cout << "f = " << f << "\n";
    cout << "\n";
    cout << "e + f = " << e + f << "\n";
    cout << "e - f = " << e - f << "\n";
    cout << "e * f = " << e * f << "\n";
    cout << "e / f = " << e / f << "\n";
    cout << "\n";

    return 0;
}
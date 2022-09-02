#include <iostream>
#include <Windows.h>
#include"Lib/fraction.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    using std::cout;
    using std::endl;
    using std::cin;

    

    /// Тест простіру імен math
    math::Fraction a(1, 9);
    math::Fraction b(3, 9);
    math::Fraction c;
    c = a + b;
    std::cout << "Дріб c = a + b = ";
    c.print();
    ///

 
    return 0;
}

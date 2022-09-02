#include <iostream>
#include <Windows.h>

#include"Lib/fraction.h"
#include"Lib/shape.h"
#include"Lib/rootsEQ.h"


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
    math::EqLine l;
    l.Solution();
    ///
    cout << "\n\n";
    /// Тест простіру імен geometry
    using namespace geometry;
    Reactangle react(10,12,5,6);
    react.Show();
    //////

 
    return 0;
}

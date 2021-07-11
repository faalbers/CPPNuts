#include <iostream>

int main()
{
    int a = 10;
    int & b = a;
    int c = a;

    std::cout << a << " " << b << " " << c << std::endl;

    a = 20;
    std::cout << a << " " << b << " " << c << std::endl;

    b = 30;
    std::cout << a << " " << b << " " << c << std::endl;
    
    c = 40;
    std::cout << a << " " << b << " " << c << std::endl;
    
    return 0;
}
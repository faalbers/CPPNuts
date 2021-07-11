#include <iostream>

int main()
{
    int a = 10, b = 20, c = 30;
    std::cout << a << " " << b << " " << c << std::endl;

    c = b = a;
    std::cout << a << " " << b << " " << c << std::endl;
    
    c = b = a++;
    std::cout << a << " " << b << " " << c << std::endl;
    
    c = b = ++a;
    std::cout << a << " " << b << " " << c << std::endl;
    
    return 0;
}
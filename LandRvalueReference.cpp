#include <iostream>

// l value reference
void add(int& x)
{
    x += 1;
}

// r value reference
void add(int&& x)
{
    x += 1;
    std::cout << "r value " << x << std::endl;
}

int main()
{
    int x = 10;
    add(x);
    std::cout << "l value " << x << std::endl;
    add(20);
    return 0;
}
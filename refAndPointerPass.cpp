#include <iostream>

void refFunc(int &x)
{
    // set value of reference
    x += 5;
}

void pointFunc(int *x)
{
    // set value of pointer
    *x += 10;
}

int main() {
    int x = 10;

    // pass as reference
    refFunc(x);

    std::cout << x << std::endl;

    // pass as pointer
    pointFunc(&x);

    std::cout << x << std::endl;

    return 0;
}
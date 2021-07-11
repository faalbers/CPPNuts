#include <iostream>

int main()
{
    int a = 8, b = 10, c = 20;

    std::cout << ((a <= 10) ? b : c) << std::endl;

    (a == 8) ? printf("It's 8\n") : ((a == 9) ? printf("It's 9\n") : printf("It's not 9\n"));

    return 0;
}
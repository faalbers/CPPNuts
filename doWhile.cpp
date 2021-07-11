#include <iostream>

int main()
{
    int x = 5;

    // entry control loop
    while( x > 0 ) {
        std::cout << x << std::endl; 
        x--;
    }

    x = 5;

    // exit control loop
    do {
        std::cout << x << std::endl; 
        x--;
    } while  ( x > 0 );
    
    return 0;
}
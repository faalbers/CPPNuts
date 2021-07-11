#include <iostream>

int main()
{
    int val;

    std::cout << "case: ";
    std::cin >> val;

    // Case does NOT work on floating point values
    
    // you need break on each case
    switch(val) {
        case 0:
            std::cout << "Zero\n";
            break;
        case 1:
            std::cout << "One\n";
            break;
        case 2:
            std::cout << "Two\n";
            break;
        case 3:
            std::cout << "Three\n";
            break;
        default:
            std::cout << "Default\n";
            break;
    }
    
    std::cout << "If you don't use break on each case\n";
    switch(val) {
        case 0:
            std::cout << "Zero\n";
        case 1:
            std::cout << "One\n";
        case 2:
            std::cout << "Two\n";
        case 3:
            std::cout << "Three\n";
        default:
            std::cout << "Default\n";
    }

    return 0;
}
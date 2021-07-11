#include <iostream>

class Base
{
    int x;  // 4 bytes
    int y;  // 4 bytes
    char a; // 1 byte
    // But Base is 12 bytes total because of structural padding, and not 9
};

struct Bose
{
    int x;  // 4 bytes
    int y;  // 4 bytes
    char a; // 1 byte
    // But Base is 12 bytes total because of structural padding, and not 9
};

void takeArray(int array[])
{
    std::cout << "Size of array in function takeArray in bytes: " << sizeof(array) << std::endl;
    std::cout << "It is 8 bytes (8*8 bits) because that is the size of a 64 bit pointer\n";
}

int main()
{
    // size of class
    std::cout << "Size of class Base in bytes: " << sizeof(Base) << std::endl;

    // size of class object
    Base b;
    std::cout << "Size of object from class Base in bytes: " << sizeof(b) << std::endl;
    
    // size of struct
    std::cout << "Size of struct Base in bytes: " << sizeof(Bose) << std::endl;

    // size of struct object
    Bose c;
    std::cout << "Size of object from struct Base in bytes: " << sizeof(c) << std::endl;

    // size of int is 4, so array of 5 ints is 20
    int array[] = {1,2,3,4,5};
    std::cout << "Size of array in bytes: " << sizeof(array) << std::endl;

    // size in elements of an array
    std::cout << "Size of elements in array: " << sizeof(array) / sizeof(array[0]) << std::endl;

    // sizeoff only knows the size of the array in the scope where it was created
    // this test will show it
    takeArray(array);

    return 0;
}
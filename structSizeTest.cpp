#include <iostream>

typedef struct sizeTest
{
    uint32_t    sizeA;
    uint16_t    sizeB;
} sizeTest;

int main()
{
    sizeTest test;
    std::cout << "Size of sizeTest should be 6, but is " << sizeof(test) << std::endl;
    return 0;
}

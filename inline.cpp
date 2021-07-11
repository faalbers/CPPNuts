#include <iostream>
#include <chrono>

unsigned long func(unsigned long val)
{
    val += 1;
    return val;
}

// inline copies the function body on the spot where it is called
inline unsigned long  funci(unsigned long val)
{
    val += 1;
    return val;
}

void funcref(unsigned long &val)
{
    val += 1;
}

// inline copies the function body on the spot where it is called
inline void funciref(unsigned long &val)
{
    val += 1;
}

int main()
{
    unsigned long a;

    auto start = std::chrono::high_resolution_clock::now();

    a = 0;
    for (int x = 0; x < 100000; x++) {
        for (int y = 0; y < 10000; y++) a = func(a);
    }

    auto t1 = std::chrono::high_resolution_clock::now();

    a = 0;
    for (int x = 0; x < 100000; x++) {
        for (int y = 0; y < 10000; y++) a = funci(a);
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    a = 0;
    for (int x = 0; x < 100000; x++) {
        for (int y = 0; y < 10000; y++) funcref(a);
    }

    auto t3 = std::chrono::high_resolution_clock::now();

    a = 0;
    for (int x = 0; x < 100000; x++) {
        for (int y = 0; y < 10000; y++) funciref(a);
    }

    auto t4 = std::chrono::high_resolution_clock::now();
    
    auto nil = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - start);
    auto il = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    auto nilr = std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2);
    auto ilr = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);

    // inline efficiency does not seem big here, but it's an official usage because
    // with inline you don't have push/pop overhead
    // return overhead
    // inefficient instruction cache usage
    std::cout << "execution time non inline           : " << nil.count() << std::endl;
    std::cout << "execution time inline               : " << il.count() << std::endl;
    std::cout << "execution time non inline referenced: " << nilr.count() << std::endl;
    std::cout << "execution time inline referenced    : " << ilr.count() << std::endl;

    return 0;
}
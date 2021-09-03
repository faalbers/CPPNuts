#include <chrono>
#include <iostream>

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "Render Time: " << ms_int.count() << "ms\n";
    return 0;
}

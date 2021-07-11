#include <iostream>

// passing copies
void rec(int times) {
    if (times == 0) return;
    std::cout << "rec(" << times << ") start\n";
    --times;
    rec(times);
    ++times;
    std::cout << "rec(" << times << ") end\n";
}

// passing reference
void recr(int &times) {
    if (times == 0) return;
    std::cout << "rec(" << times << ") start\n";
    --times;
    rec(times);
    ++times;
    std::cout << "rec(" << times << ") end\n";
}

int main()
{
    int times = 10;
    rec(times);
    recr(times);
    return 0;
}
#include <iostream>

void test(int x) { std::cout << "copy \n"; }
void test(int& x) { std::cout << "reference \n"; }

int main()
{
    int x = 10;
    // it's not sure what test function to use, ambigous
    //test(x);
    return 0;
}
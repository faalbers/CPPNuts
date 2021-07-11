// Testing function overload of inherited class

#include <iostream>

class One
{
    public:
        double test(double x) { std::cout << "One::test "; return x; }
        double testA(double x) { std::cout << "One::testA "; return x; }
};

class Two : public One
{
    public:
        // scopes are not inherited
        // if using is not used , calling test with a double will still use
        // the one in scope Two, not the one in scope One
        // To put the function of scope One into Scope Two you need to add using
        using One::test;
        int test(int x) { std::cout << "Two::test "; return x; }
        int testB(int x) { std::cout << "Two::testB "; return x; }
};

int main()
{
    Two two;
    std::cout << "two.test(10) " << two.test(10) << std::endl;
    std::cout << "two.test(10.1) " << two.test(10.1) << std::endl;
    std::cout << "two.testA(10) " << two.testA(10) << std::endl;
    std::cout << "two.testA(10.1) " << two.testA(10.1) << std::endl;
    std::cout << "two.testB(10) " << two.testB(10) << std::endl;
    std::cout << "two.testB(10.1) " << two.testB(10.1) << std::endl;

    return 0;
}
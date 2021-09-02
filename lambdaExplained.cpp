#include <iostream>
#include <string>

class Base
{
public:
    Base() : name("Base") {}

    std::string name;

};

class DerivedA : public Base
{
public:
    DerivedA() : nameA("DerivedAA") { name = "DerivedA"; }

    std::string nameA;
};

class DerivedB : public Base
{
public:
    DerivedB() : nameB("DerivedAB") { name = "DerivedB"; }

    std::string nameB;
};

int main()
{
    DerivedA *DAtest = new DerivedA;

    Base *Btest = DAtest;

    auto hello = [](Base * baser) { std::cout << ((DerivedA *)baser)->nameA << std::endl; };

    hello(Btest);

    return 0;
}
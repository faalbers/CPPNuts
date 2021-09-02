#include <iostream>
#include <string>
#include <map>

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

template<typename T>
T * getTypeA(Base * ptr) { return (T *) ptr; }

template<typename T>
Base * getTypeB(Base * ptr) { return (T *) ptr; }

typedef DerivedA * DerivedAPtr; 

int main()
{
    DerivedA *DAtest = new DerivedA;

    Base *Btest = DAtest;

    auto testA = &getTypeA<DerivedA>;
    auto testB = &getTypeB<DerivedA>;

    auto resultA = getTypeA<DerivedA>(Btest);
    auto resultB = getTypeB<DerivedA>(Btest);

    std::map<std::string, DerivedA *> test_map;

    test_map["testje"] = DAtest;

    std::cout << test_map["testje"]->nameA << std::endl;

    return 0;
}
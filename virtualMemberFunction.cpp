#include <iostream>

class BaseA
{
public:
    BaseA() {}
    void sayA() { std::cout << "A BaseA\n"; }
    virtual void sayB() { std::cout << "B BaseA\n"; }    // virtual function
    // pure virtual function is forced to be declared in derived class.
    // if you do not add = 0 and it is not declared in derived class it will break the linker.
    // with = 0 added the compiler will give a proper error.
    // once the base class has a virtual function it becomes an abstract class.
    // even if the pure function is declared in the derived class
    // if it is not declared in derived class the derived class become abstract too.
    virtual void sayC() = 0;                            // pure virtual function
};

class DerivedBaseA : public BaseA
{
public:
    void sayA() { std::cout << "A DerrivedBaseA\n"; }
    void sayB() { std::cout << "B DerrivedBaseA\n"; }
    void sayC() { std::cout << "C DerrivedBaseA\n"; }
    void sayD() { std::cout << "D DerrivedBaseA\n"; }
};

class BaseB
{
public:
    BaseB() {}
    void sayA() { std::cout << "A BaseB\n"; }
    virtual void sayB() { std::cout << "B BaseB\n"; }    // virtual function
    virtual void sayC() { std::cout << "C BaseB\n"; }    // virtual function
};

class DerivedBaseB : public BaseB
{
public:
    void sayA() { std::cout << "A DerrivedBaseB\n"; }
    void sayB() { std::cout << "B DerrivedBaseB\n"; }
    void sayC() { std::cout << "C DerrivedBaseB\n"; }
    void sayD() { std::cout << "D DerrivedBaseB\n"; }
};

int main()
{
    // Derived object set in Base pointer
    BaseA *derivedBaseAA = new DerivedBaseA;
    // Derived object
    DerivedBaseA derivedBaseA;
    // Referenced Derived Object set as Base Object
    BaseA &derivedBaseAB = derivedBaseA;

    // derivedBaseAA (BaseA) points to DesrivedBaseA object
    // derivedBaseAB (BaseA) is a DerivedBaseA object

    derivedBaseAA->sayA();  // Overloaded function
    derivedBaseAB.sayA();   // Overloaded function
    derivedBaseAA->sayB();  // Virtual funtion
    derivedBaseAB.sayB();   // Virtual funtion
    derivedBaseAA->sayC();  // Pure Virtual function
    derivedBaseAB.sayC();   // Pure Virtual function
    // this does not work because virtual does not exist in BaseA
    //derivedBaseAA->sayD();
    //derivedBaseAB.sayD();
    // but it does exist in Derrived
    derivedBaseA.sayD();
    derivedBaseA.sayD();
    std::cout << std::endl;

    // we can not create a BaseA object because the class is abstract.
    // this is because it contains a pure virtual function
    //BaseA *baseA = new BaseA;
    // this will work because it has no pure virtual function
    BaseB *baseB = new BaseB;
    baseB->sayA();

    return 0;
}
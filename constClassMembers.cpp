#include <iostream>

class BaseA
{
    int x_;
public:
    BaseA(int x = 0) : x_(x) {}

    // following const overload with pass by value does not work
    //void print(int val) { std::cout << val << std::endl; }
    //void print(const int val) { std::cout << val << std::endl; }

    // const overload with pass by reference does work
    void print(int &val) {
        std::cout << "BaseA::print(int&): " << val << std::endl;
        // allowed to change
        val += 1;
    }
    void print(const int &val) {
        std::cout << "BaseA::print(const int&): " << val << std::endl;
        // not allowed to change value
        //val += 1;
    }

    // const overload with pass by pointer does work
    void print(int *val) {
        std::cout << "BaseA::print(int*): " << *val << std::endl;
        // allowed to change
        *val += 1;
    }
    void print(const int *val) {
        std::cout << "BaseA::print(const int*): " << *val << std::endl;
        // not allowed to change value
        //*val += 1;
    }

};

class BaseB
{
public:
    void print() { std::cout << "BaseB::print()\n"; }
    void print() const { std::cout << "BaseB::print() const\n"; }
};

class BaseC
{
public:
    void print() const { std::cout << "BaseC::print() const\n"; }
};

class BaseD
{
public:
    void print() { std::cout << "BaseD::print()\n"; }
};

int main()
{
    BaseA ba;
    
    // pass by reference
    int a = 1;
    ba.print(a);
    std::cout << "changed pass by reference value: " << a << std::endl;
    a = 1;

    const int b = 1;
    ba.print(b);
    
    // pass by pointer
    ba.print(&a);
    std::cout << "changed pass by pointer value: " << a << std::endl;

    ba.print(&b);

    // const object using non const members
    BaseB bb;
    bb.print();

    // const object using const members
    const BaseB bbc;
    bbc.print();

    // this works though, probably because nothing is changed inside
    BaseC bc;
    bc.print();
    
    // this does not work, no const funtion for const object
    const BaseD bd;
    // bd.print();

    return 0;
}
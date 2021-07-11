#include <iostream>

class Base
{
    int a_, b_;
    public:
        Base() : Base(0,0) {};
        Base(int a) : Base(a,0) {}
        Base(int a, int b) : a_(a), b_(b) {}
        void print() { std::cout << a_ << " " << b_ << std::endl; }
};

int main()
{
    Base a;
    Base b(10);
    Base c(10,20);
    a.print();
    b.print();
    c.print();
}
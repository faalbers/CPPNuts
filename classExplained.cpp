#include <iostream>

class Base
{
// class is default private, struct is not
    double x_;
    double y_;

public:
    // default constructor
    Base() {x_=0; y_=0; std::cout << "Base::Base()\n"; }
    // parametrized constructor
    Base(double x, double y) {x_=x; y_=y; std::cout << "Base::Base(double, double)\n"; }
    // copy constructor
    Base(const Base &rhs) {x_=rhs.x_; y_=rhs.y_; std::cout << "Base::Base(const Base&)\n";}

    void print() {std::cout << x_ << " , " << y_ << std::endl;}
};
int main()
{
    Base a;
    a.print();

    Base b(1.3, 1.4);
    b.print();
    
    Base c = b;
    c.print();
    
    return 0;
}
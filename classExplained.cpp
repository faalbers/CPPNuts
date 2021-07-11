#include <iostream>

class Base
{
// class is default private, struct is not
    double x_;
    double *y_;
    bool   deleteY_;
public:
    // default constructor
    //Base() {x_=0; y_=new double(0); std::cout << "Base::Base()\n"; }
    Base() : x_(0), y_(new double(0)), deleteY_(true)
    {
        std::cout << "Base::Base()\n";
    }

    // parametrized constructors
    //Base(double x, double y) {x_=x; y_=new double(y); std::cout << "Base::Base(double, double)\n"; }
    Base(double x, double y) : x_(x), y_(new double(y)), deleteY_(true)
    {
        std::cout << "Base::Base(double, double)\n";
    }

    Base(double x, double *y) : x_(x), y_(y), deleteY_(false)
    {
        std::cout << "Base::Base(double, double*)\n";
    }

    // copy constructor
    //Base(const Base &rhs) {x_=rhs.x_; y_=new double(*rhs.y_); std::cout << "Base::Base(const Base&)\n";}
    Base(const Base &rhs) : x_(rhs.x_), y_(new double(*rhs.y_)), deleteY_(true)
    {
        std::cout << "Base::Base(const Base&)\n";
    }

    // destructor
    ~Base()
    {
        std::cout << "Base::~Base()\n";
        if (deleteY_) {
            std::cout << "delete y_\n";
            delete y_;
        }
    }

    void print() {std::cout << x_ << " , " << *y_ << " , delete: " << deleteY_ << std::endl;}
};

int main()
{
    Base a;
    a.print();

    Base b(1.3, 1.4);
    b.print();
    
    Base c = b;
    c.print();

    double *y = new double(2.4);
    Base d(2.3, y);
    d.print();
    
    return 0;
}
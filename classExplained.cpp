#include <iostream>

class Base
{
// class is default private, struct is not
    // private data members
    double x_;
    double *y_;
    bool   deleteY_;
    // this const value will be set with an initializer list
    const int const_;
    // this reference member needs to be initialized with a initializer list
    int &ref_;
    // a const member fuction can not change any member data in a class except for mutable member data
    mutable int mutTest_ = 1000;
public:
    // default constructor with initialization
    //Base() {x_=0; y_=new double(0); std::cout << "Base::Base()\n"; }
    Base(int &ref) : x_(0), y_(new double(0)), deleteY_(true), const_(100), ref_(ref)
    {
        std::cout << "Base::Base()\n";
    }

    // parametrized constructors with initialization
    //Base(double x, double y) {x_=x; y_=new double(y); std::cout << "Base::Base(double, double)\n"; }
    Base(double x, double y, int &ref) : x_(x), y_(new double(y)), deleteY_(true), const_(100), ref_(ref)
    {
        std::cout << "Base::Base(double, double, int&)\n";
    }

    Base(double x, double *y, int &ref) : x_(x), y_(y), deleteY_(false), const_(100), ref_(ref)
    {
        std::cout << "Base::Base(double, double*, int&)\n";
    }

    // copy constructor
    //Base(const Base &rhs) {x_=rhs.x_; y_=new double(*rhs.y_); std::cout << "Base::Base(const Base&)\n";}
    Base(const Base &rhs) : x_(rhs.x_), y_(new double(*rhs.y_)), deleteY_(true), const_(rhs.const_), ref_(rhs.ref_)
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

    // operator= can not be implemented because there is no Base() constructor
    // We can not create a Base() constructor because we HAVE to initialize the
    // ref_ reference parameter with an incoming referenced parameter
    Base& operator=(const Base& rhs)
    {
        x_ = rhs.x_;
        y_ = new double(*rhs.y_);
        // const_ does not need to be copied because all other objects already have it
        // and const_ = rhs.const_ will give an error anyway since it was already assigned
        deleteY_ = true;
        ref_ = rhs.ref_;
        a = rhs.a;
        return *this;
    }

    // operator + overload
    Base operator+ (const Base &rhs)
    {
        Base b(ref_);
        b.x_ = x_ + rhs.x_;
        *b.y_ = *y_ + *rhs.y_;
        b.deleteY_ = true;
        b.a = a + rhs.a;
        return b;
    }
    
    // unary operator - overload
    Base operator- ()
    {
        Base b(-x_, -*y_, ref_);
        b.deleteY_ = true;
        b.a = -a;
        return b;
    }

    void printPrivate() {std::cout
        << "x_\t = " << x_ << "\ny_\t = " << *y_ << "\ndeleteY_ = " << deleteY_
        << "\nconst_\t = " << const_ << "\nref_\t = " << ref_ << std::endl;}
    
    // non static member functions can access both static and non static data members
    void printPublic() {std::cout << "a\t = " << a << "\nb\t = " << b << "\nc\t = " << c << std::endl;}

    // the following gives an error because static member functions can not access non static data members
    //static void printAB() {std::cout << "a\t = " << a << "\nb\t = " << b << std::endl;}

    // this one only access static data members
    static void printB() {
        std::cout << "printB is a static function, so it only access static data members\n";
        std::cout << "b\t = " << b << std::endl;
    }

    // since it only access static member, this->b does not work because it has no access to the object
    /*
    static void printBThis() {
        std::cout << "b\t = " << this->b << std::endl;
    }
    */

    // this will work here because it has access to the object
    void printBThis() {
        std::cout << "printBThis is not a static function, so it can access the object with this\n";
        std::cout << "b\t = " << this->b << std::endl;
    }


    // print object address
    void objectAddress() { std::cout << this << std::endl; }

    // adding functions below as friend
    friend void setX(Base &, double);
    friend double getX(Base &);

    // adding class as friend
    friend class GetSet;

    void constChangeTest() const
    {
        // this does not work because function is const and member data us not mutable
        //x_ = 5000;

        // but changing a mutable data member does work
        mutTest_ = 5000;
    }

    // public data members
    int a = 0;  // declaration (memory allocation) and initialization is done during object construction
    static int b; // decleration (memory allocation) needs to be done outside of the class scope
    const int c = 50; // const data member declared and initialized, can not be changed anymore
};

// declaration (memory allocation) for static class member
// this should happen in the cpp file and not the header
//int Base::b;
// you can also add an initialization to the declared static member
int Base::b = 0;

// this will not work because x_ is private
// by adding it the class Base a s friend it will work
void setX(Base &obj, double x)
{
    obj.x_ = x;
}

double getX(Base &obj)
{
    return obj.x_;
}

// we can also make a class be a friend of another class
class GetSet
{
public:
    void setX(Base &obj, double x) { obj.x_ = x; }
    double getX(Base &obj) { return obj.x_; }
};

class Derived : public Base
{
public:
    Derived(int &ref) : Base(ref) {}
};

int main()
{
    // param to be referenced
    int refVal = 50;

    std::cout << "Base a;\n";
    Base a(refVal);
    a.printPrivate();
    a.printPublic();
    // you can assign a static member like this
    Base::b = 10;
    a.printPublic();
    // or you can assign a static member like this
    // remember, this value will be the same for all created objects
    a.b = 20;
    a.printPublic();
    std::cout << std::endl;

    std::cout << "Base b;\n";
    Base b(1.3, 1.4, refVal);
    b.printPrivate();
    // here you can see this object points to the same static class member
    a.printPublic();
    std::cout << std::endl;
    
    std::cout << "Base c;\n";
    Base c = b;
    c.printPrivate();
    std::cout << std::endl;

    std::cout << "Base cc;\n";
    int refValB = 1000;
    Base cc(refValB);
    cc = b;
    cc.printPrivate();
    std::cout << std::endl;

    std::cout << "Base d;\n";
    double *y = new double(2.4);
    Base d(2.3, y, refVal);
    d.printPrivate();

    std::cout << "Static Funtions\n";
    d.printB();
    Base::printB();
    std::cout << std::endl;
    
    // changing referenced refVal
    std::cout << "Changed refVal = 200\n";
    refVal = 200;
    a.printPrivate();
    b.printPrivate();
    c.printPrivate();
    cc.printPrivate();
    d.printPrivate();
    std::cout << std::endl;

    std::cout << "object addresses\n";
    a.objectAddress();
    b.objectAddress();
    c.objectAddress();
    cc.objectAddress();
    d.objectAddress();
    std::cout << std::endl;

    std::cout << "static this test\n";
    a.printB();
    a.printBThis();
    std::cout << std::endl;

    std::cout << "using friend function setX to set privat x_\n";
    setX(a, 5.3);
    std::cout << getX(a) << std::endl;

    std::cout << "using friend class to set privat x_\n";
    GetSet gs;
    std::cout << gs.getX(a) << std::endl;
    gs.setX(a, 6.3);
    std::cout << getX(a) << " " << gs.getX(a) << std::endl;
    std::cout << std::endl;

    std::cout << "friends of inherited class seem to automatically become friends of derived class\n";
    Derived der(refVal);
    der.printPrivate();
    gs.setX(der, 20.5);
    std::cout << getX(der) << " " << gs.getX(der) << std::endl;
    std::cout << std::endl;

    std::cout << "operator overload example\n";
    Base e(refVal);
    b.a = 4;
    d.a = 5;
    e = b + d;
    b.printPrivate();
    b.printPublic();
    d.printPrivate();
    d.printPublic();
    e.printPrivate();
    e.printPublic();
    std::cout << std::endl;

    std::cout << "unary operator overload example\n";
    Base f(refVal);
    f = -b;
    f.printPrivate();
    f.printPublic();
    std::cout << std::endl;

    return 0;
}
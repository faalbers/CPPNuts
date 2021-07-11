class Base
{
    int a_;

    public:
        Base () {}  // default constructor
        Base(int a = 0) : a_(a) {} // also default constructor since it has a default value
};

int main()
{
    // compile error because there are 1 default constructors
    Base b; // calling default constructor
    return 0;
}
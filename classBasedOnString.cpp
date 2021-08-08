#include <iostream>
#include <string>
#include <memory>

/*
class atom
{
public:
    virtual void say();
};

class aaa : public atom
{
public:
    void say() { std::cout << "aaa\n"; }
};

class bbb : public atom
{
public:
    void say() { std::cout << "bbb\n"; }
};

template<typename T>
T *MyObj(){
    return new T;
}
*/

class atom
{
public:
    virtual void say();
};

class aaa: public atom
{
public:
    aaa() { say(); }
    virtual void say() { std::cout << "aaa\n"; }
};

class bbb: public atom
{
public:
    virtual void say() { std::cout << "bbb\n"; }
};

template<typename T>
atom *MyAtom(){
    return new T;
}

int main()
{
    std::string type = "aaa";

    //MyObj<aaa>();

    std::shared_ptr<int> babe(new int(5));
    std::cout << *babe << std::endl;

    std::shared_ptr<atom> test(MyAtom<aaa>());

    test->say();

    // virtual test
    bbb bbbtest;

    bbbtest.say();

    return 0;
}

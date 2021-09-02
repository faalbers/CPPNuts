#include <memory>
#include <iostream>

class A
{
public:
    A() { std::cout << "create\n"; }
    ~A() { std::cout << "delete\n"; }
    int a;
};

int main()
{
    std::cout <<"START" << std::endl;

    std::shared_ptr<A> myA;
    std::shared_ptr<A> myB( new A );

    if ( myA == nullptr ) std::cout <<"NO OBJECT" << std::endl;
    myB->a = 5;

    std::cout << myB->a << std::endl;

    myA = myB;

    std::cout << myA->a << std::endl;

    std::cout <<"END" << std::endl;

    return 0;
}
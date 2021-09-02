#include <memory>
#include <iostream>
#include <string>

class atom
{

};

class test : public atom
{
public:
    test() : name("test") {}
    ~test() { std::cout << "Destroyed\n"; }

    std::string name;
};

int main()
{
    std::shared_ptr<atom> keepIt;
    {
        std::shared_ptr<test> helloSptr(new test);
        keepIt = helloSptr;
    }
    std::shared_ptr<test> another((test *) keepIt.get());
    std::cout << another->name << std::endl;
    std::cout << "back\n";


    return 0;
}
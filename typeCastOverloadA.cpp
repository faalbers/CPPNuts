// doing typecast overload with classes that use eachother
// using sepperate class includes
// forward casting sollution explained in typeCastOverload.cpp

#include <iostream>
#include "Dollar.hpp"
#include "Euro.hpp"

int main()
{
    Dollar da(10);
    Euro ea;
    ea = da;
    std::cout << da << " = " << ea << std::endl;
    
    Euro eb(10);
    Dollar db;
    db = eb;
    std::cout << db << " = " << eb << std::endl;

    return 0;
}
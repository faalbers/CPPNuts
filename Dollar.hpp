#ifndef _DOLLAR_H_
#define _DOLLAR_H_

#include "MoneyRates.hpp"
#include <iostream>

// do not include Euro class here, it will be included in the definition cpp file
// we use forward declaration
class Euro;

class Dollar
{
    double d_;
public:
    Dollar(double d = 0.0);

    // since operator << will access private data, it needs to be friend of class
    friend std::ostream& operator << (std::ostream&, Dollar&);

    // typecast overload for Euro
    operator Euro();
};

std::ostream& operator << (std::ostream& output, Dollar& obj);

#endif

#ifndef _EURO_H_
#define _EURO_H_

#include "MoneyRates.hpp"
#include <iostream>

// do not include Dollar class here, it will be included in the definition cpp file
// we use forward declaration
class Dollar;

class Euro
{
    double e_;
public:
    Euro(double e = 0.0);

    friend std::ostream& operator << (std::ostream&, Euro&);

    // typecast overload for Dollar
    operator Dollar();
};

std::ostream& operator << (std::ostream& output, Euro& obj);

#endif

#include "Dollar.hpp"
#include <iostream>
#include <iomanip>
#include "Euro.hpp"

Dollar::Dollar(double d) : d_(d)
{

}

Dollar::operator Euro()
{
    return Euro( d_ * EURO_UNIT );
}

std::ostream& operator << (std::ostream& output, Dollar& obj)
{
    // also format the floating point values
    output << std::fixed << std::setprecision(2) << obj.d_ << " Dollar";
    return output;
}

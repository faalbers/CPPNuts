#include "Euro.hpp"
#include <iostream>
#include <iomanip>
#include "Dollar.hpp"

Euro::Euro(double e) : e_(e)
{

}

Euro::operator Dollar()
{
    return Dollar( e_ / EURO_UNIT );
}

std::ostream& operator << (std::ostream& output, Euro& obj)
{
    // also format the floating point values
    output << std::fixed << std::setprecision(2) << obj.e_ << " Euro";
    return output;
}

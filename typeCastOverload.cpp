#include <iostream>
#include <iomanip>

#define EURO_UNIT 1.18

class Dollar;

class Euro
{
    double e_;
public:
    Euro(double e = 0.0) : e_(e) {}

    friend std::ostream& operator << (std::ostream&, Euro&);

    // the conversion needs to see the full definition of the Dollars class, so we declare it here
    // but define it later
    operator Dollar();
};

std::ostream& operator << (std::ostream& output, Euro& obj)
{
    // also format the floating point values
    output << std::fixed << std::setprecision(2) << obj.e_ << " Euro";
    return output;
}

class Dollar
{
    double d_;
public:
    Dollar(double d = 0.0) : d_(d) {}

    friend std::ostream& operator << (std::ostream&, Dollar&);

    operator Euro() { return Euro( d_ * EURO_UNIT ); }
};

std::ostream& operator << (std::ostream& output, Dollar& obj)
{
    // also format the floating point values
    output << std::fixed << std::setprecision(2) << obj.d_ << " Dollar";
    return output;
}

// we now define it because the full definition of the Dollars class is done
Euro::operator Dollar() { return Dollar( e_ / EURO_UNIT ); }

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
#include <iostream>
 
 
class Dollars; //forward declaration of Dollars here is needed to define the conversion inside Cents
 
class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0)
        : m_cents{ cents }
    {
    }
 
    // Overloaded int cast
    operator int() const { return m_cents; }
 
    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
 
    //the conversion needs to see the full definition of the Dollars class, so we declare it here
    operator Dollars() const; 
};
 
class Dollars
{
private:
    double m_dollars;
public:
    Dollars(double dollars = 0)
        : m_dollars{ dollars }
    {
    }
    //Overloaded double cast
    operator double() const { return m_dollars; }
 
    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents(static_cast<int>(m_dollars) * 100); }
};
 
Cents::operator Dollars() const { return Dollars(static_cast<double>(m_cents) / 100); } //and define it here
 
void printCents(Cents cents)
{
    std::cout << cents << '\n'; // cents will be implicitly cast to an int here
}
 
void printDollars(Dollars dollars)
{
    std::cout << dollars << '\n'; // dollars will be implicitly cast to an double here
}
 
int main()
{
    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here
    Cents cents{ 10 };
    printDollars(cents); // cents will be implicitly cast to a Dollars here
 
    std::cout << '\n';
 
    return 0;
}
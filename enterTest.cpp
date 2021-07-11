#include <iostream>

int main()
{
    int x;
    std::string str;

    // this takes a full line
    std::cout << "Enter a line: ";
    std::getline(std::cin, str);
    std::cout << "You entered '" << str << "'" << std::endl;

    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "You entered " << x << std::endl;

    // this only takes words with no spaces
    std::cout << "Enter a word: ";
    std::cin >> str;
    std::cout << "You entered '" << str << "'" << std::endl;

    return 0;
}
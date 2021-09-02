#include <iostream>

int main()
{
    char wordA[4] = { 'a', 'b', 'c', 'd'};
    char wordB[4] = { 'c', 'd', 'e', '\0'};
    std::string word;

    //char shortWord[4];

    word = std::string(wordA);
    std::cout << word << std::endl;
    word = std::string(wordA).substr (0,4);
    std::cout << word << std::endl;

    return 0;
}
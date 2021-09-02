#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> listA;
    for ( int i = 0; i < 10; i++ ) listA.push_back(i);

    std::reverse(listA.begin(),listA.end());

    while ( !listA.empty() ) {
        std::cout << listA.back() << std::endl;
        listA.pop_back();
    }

    return 0;
}
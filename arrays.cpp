#include <iostream>

int main()
{
    int number[] = {1,2,3,4,5,6,7,8,9};

    std::cout << number[4] << " " << 4[number] << " " << *(number + 4) << " " << *(4 + number) << std::endl;

    // since number is just an address
    std::cout << number << " " << number + 4 << " " << &(number[4]) << " " << *(number + 4) << std::endl;

    int matrixA[3][3] = {1,2,3,4,5,6,7,8,9};
    
    int matrixB[][3] = {1,2,3,4,5,6,7,8,9};
    
    int matrixC[][2] = {1,2,3,4,5,6,7,8,9};

    std::cout << matrixA[1][2] << " " << matrixB[1][2] << " " << matrixC[1][2] << " " << std::endl;

    int matrixD[3][3] = {   {1,2,3},
                            {4,5,6},
                            {7,8,9}
                        };
    int matrixE[][3] =  {   {1,2,3},
                            {4,5,6},
                            {7,8,9}
                        };

    std::cout << matrixD[1][2] << " " << matrixE[1][2] << std::endl;

    // This is like accessing start a column 1 of 3 size columns and find index 4 on it
    std::cout << matrixD[1][4] << " = " << matrixD[2][1] << std::endl;

    return 0;
}
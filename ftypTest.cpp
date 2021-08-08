#include <iostream>
#include "ftyp.hpp"

int main()
{
    MP4Lib::atom *ftypObj(new MP4Lib::ftyp);

    ftypObj->say();
    //ftypObj->handleData_();

    delete ftypObj;

    return 0;
}
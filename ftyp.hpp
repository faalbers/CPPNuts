#ifndef MP4LIB_FTYP_H
#define MP4LIB_FTYP_H

#include "atom.hpp"
#include <fstream>
/*
namespace MP4Lib
{

class ftyp : public atom
{
public:
    ftyp(std::shared_ptr<std::ifstream> file);

    virtual void handleData_();

protected:
};

}
*/
namespace MP4Lib
{

class ftyp: public atom
{
public:
    ftyp();
    
    void say();

    //virtual void handleData_();
};

}

#endif
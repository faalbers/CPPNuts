#ifndef MP4LIB_ATOM_H
#define MP4LIB_ATOM_H

#include <string>
#include <memory>
#include <fstream>

/*
namespace MP4Lib
{

class atom
{
public:
    atom(std::shared_ptr<std::ifstream> file);

    int64_t getSize();

    virtual void handleData_();


protected:

    std::string                     type_;
    std::shared_ptr<std::ifstream>  file_;
    int64_t                         filePosition_;
    uint64_t                        size_;
    int64_t                         dataOffset_;
	uint64_t                        dataSize_;
};

}
*/

namespace MP4Lib
{

class atom
{
public:
    atom();
    
    virtual void say() = 0;

    //virtual void handleData_();

};

}

#endif
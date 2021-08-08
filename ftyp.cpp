#include "ftyp.hpp"

#include <iostream>

/*
MP4Lib::ftyp::ftyp(std::shared_ptr<std::ifstream> file)
    : atom(file)
{
    if ( type_ != "ftyp" )
        throw std::runtime_error("Error: Wrong atom object creation of type ftyp");

    handleData_();
}

void MP4Lib::ftyp::handleData_()
{
    std::cout << "Type         : " << type_ << std::endl;
    std::cout << "File Position: " << filePosition_ << std::endl;
    std::cout << "Atom Size    : " << size_ << std::endl;
    std::cout << "Data Offset  : " << dataOffset_ << std::endl;
    std::cout << "Data Size    : " << dataSize_ << std::endl;
}
*/

MP4Lib::ftyp::ftyp()
    : atom()
{

}

void MP4Lib::ftyp::say() {
    std::cout << "ftyp\n";
}

/*
MP4Lib::ftyp::ftyp()
    : atom()
{
    say();
    handleData_();
}


void MP4Lib::ftyp::say() {
    std::cout << "aaa\n";
}

void MP4Lib::ftyp::handleData_()
{
    std::cout << "handling data" << std::endl;
}
*/
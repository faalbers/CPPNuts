#include "atom.hpp"
#include <intrin.h> // for byte swapping

#include <iostream>
/*
MP4Lib::atom::atom(std::shared_ptr<std::ifstream> file)
    : file_(file)
    , type_("....")
{
    char        typeName[] = "....";
    uint32_t    size32;

    filePosition_ = file_->tellg();

    // get size and type
    file_->read((char *) &size32, sizeof(size32));
    file_->read((char *) typeName, 4);
    type_ = std::string(typeName);

    // byte order needs to be swapped
    size32 = _byteswap_ulong(size32);

    // if size == 1 we need to fetch the large size
    if ( size32 == 1 ) {
        file_->read((char *) &size_, sizeof(size_));
        size_ = _byteswap_uint64(size_);
    } else {
        size_ = size32;
    }

    dataOffset_ = file_->tellg() - filePosition_;
    dataSize_ = size_ - dataOffset_;

    file_->seekg (filePosition_, file_->beg);

    std::cout << "Type         : " << type_ << std::endl;
    std::cout << "File Position: " << filePosition_ << std::endl;
    std::cout << "Atom Size    : " << size_ << std::endl;
    std::cout << "Data Offset  : " << dataOffset_ << std::endl;
    std::cout << "Data Size    : " << dataSize_ << std::endl;
}

int64_t MP4Lib::atom::getSize() { return size_; }

void handleData_() {}
*/

MP4Lib::atom::atom()
{

}

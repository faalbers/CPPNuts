#include <memory>
#include <vector>
#include <string>
#include <iostream>

class atom
{
public:
    atom(std::string thisType) : type(thisType) {}

    std::string type;
};

class ftyp :public atom
{
public:
    ftyp() : atom("ftyp")
    {
        data.a = 1;
        data.b = 2;
        data.c = 3;
    }

    typedef struct dataType
    {
        int a;
        double b;
        int c;
    } dataType;

    static dataType *getData(std::shared_ptr<atom> atomSPtr)
    {
        if ( atomSPtr->type == typeString ) return &((ftyp *) atomSPtr.get())->data;
        return nullptr;
    }

    static std::vector<dataType *> getDataList(std::vector<std::shared_ptr<atom>> atomSPtrs)
    {
        std::vector<dataType *> dataList;
        for ( int i = 0; i < atomSPtrs.size(); i++ ) {
            if ( atomSPtrs[i]->type == typeString )
                dataList.push_back(&((ftyp *) atomSPtrs[i].get())->data);
        }
        return dataList;
    }

    static std::string typeString;
    dataType data;
    
};

std::string ftyp::typeString = "ftyp";

struct mdat_data
{
	int d;
	double e;
};


class mdat :public atom
{
public:
    mdat() : atom("mdat")
    {
        data.d = 4;
        data.e = 5;
    }

    typedef struct dataType
    {
        double d;
        int e;
    } dataType;

    static dataType *getData(std::shared_ptr<atom> atomSPtr)
    {
        if ( atomSPtr->type == typeString ) return &((mdat *) atomSPtr.get())->data;
        return nullptr;
    }

    static std::vector<dataType *> getDataList(std::vector<std::shared_ptr<atom>> atomSPtrs)
    {
        std::vector<dataType *> dataList;
        for(auto atomSPtr : atomSPtrs) {
            if ( atomSPtr->type == typeString )
                dataList.push_back(&((mdat *) atomSPtr.get())->data);
        }
        return dataList;
    }

    static std::string typeString;
    dataType data;
};

std::string mdat::typeString = "mdat";

int main()
{
    std::vector<std::shared_ptr<atom>> children;

    children.push_back(std::make_shared<ftyp>());
    children.push_back(std::make_shared<mdat>());
    children.push_back(std::make_shared<ftyp>());

    auto *final = ftyp::getData(children[0]);

    if ( final != nullptr ) {
        std::cout << final->a << std::endl;
        std::cout << final->b << std::endl;
    }

    std::cout << std::endl;

    auto ftypDataList = ftyp::getDataList(children);
    for(auto data : ftypDataList) {
        std::cout << data->a << std::endl;
        std::cout << data->b << std::endl;
        std::cout << data->c << std::endl;
        std::cout << std::endl;
    }

    auto mdatDataList = mdat::getDataList(children);
    for(auto data : mdatDataList) {
        std::cout << data->d << std::endl;
        std::cout << data->e << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
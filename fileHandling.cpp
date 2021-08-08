#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main()
{
    int w, r;
    // std::ofstream can use string but stat64 can't
    char const filenameCPP[] = "testCPP.bin";

    // In C++

    // create a binary file handler to write to
    // filename can take std::string or char*
    std::ofstream wfileCPP(filenameCPP, std::ios::binary);

    // write the variable int p binary ito the binary file
    w = 123;
    std::cout << "CPP Write value: " << w << " bytes" << std::endl;

    // enter pointer of variable w and give the byte size of w
    wfileCPP.write((char *) &w, sizeof(w));

    // close the file handler
    wfileCPP.close();

    // get stats of file before reading it
    // this is a C thing, have to find out the C++ way of doing this
    //struct stat filestat;
	//stat(filenameCPP, &filestat);

    // The stat64 structure is similar to the stat structure, except that
    // it is capable of returning information about files that are larger than 2 GB
    struct stat64 filestat;
	stat64(filenameCPP, &filestat);

    std::cout << "CPP file size: " << filestat.st_size << " bytes" << std::endl;

    // create a binary file handler to read from
    std::ifstream rfileCPP(filenameCPP, std::ios::binary);

    // enter pointer of variable r and give the byte size of r
    rfileCPP.read((char *) &r, sizeof(r));

    // close the file handler
    rfileCPP.close();

    std::cout << "CPP Read value: " << r << std::endl;

    // In C
    char const filenameC[] = "testC.bin";

    w = 456;
    std::cout << "C Write value: " << w << std::endl;

    FILE * wfileC = fopen (filenameC, "w+");
    fwrite(&w, sizeof(w), 1, wfileC);
    
    fclose(wfileC);

    // get file stat
	stat64(filenameC, &filestat);

    std::cout << "C file size: " << filestat.st_size << " bytes" << std::endl;

    FILE * rfileC = fopen (filenameC, "r");
    fread(&r, sizeof(r), 1, rfileC);
    
    fclose(wfileC);

    std::cout << "C Read value: " << r << std::endl;

    // seek in file = move current position
        // std::ofstream can use string but stat64 can't
    char const filenamSeek[] = "../sample.MP4";

    std::ifstream sfile(filenamSeek, std::ios::binary);

    // get 2 values
    std::cout << "Current position: " << sfile.tellg() << std::endl;
    sfile.read((char *) &r, sizeof(r));
    std::cout << "read value: " << r << std::endl;
    sfile.read((char *) &r, sizeof(r));
    std::cout << "read value: " << r << std::endl;
    std::cout << "Current position: " << sfile.tellg() << std::endl;

    // get length of file and jump back to start:
    sfile.seekg (0, sfile.end);
    uint64_t length = sfile.tellg();
    sfile.seekg (0, sfile.beg);
    std::cout << "file length: " << length << std::endl;

    // get 2 values
    std::cout << "Current position: " << sfile.tellg() << std::endl;
    sfile.read((char *) &r, sizeof(r));
    std::cout << "read value: " << r << std::endl;
    sfile.read((char *) &r, sizeof(r));
    std::cout << "read value: " << r << std::endl;
    std::cout << "Current position: " << sfile.tellg() << std::endl;

    // go back to beginning of file
    sfile.seekg (0, sfile.beg);
    
    // read file into buffer
    //char * buffer = new char [length];
    char * buffer = new char [40];

    // read data as a block:
    //sfile.read (buffer,length);
    sfile.read (buffer,20);

    // print buffer char content:
    std::cout.write (buffer,40); std::cout << std::endl;

    sfile.close();

    delete[] buffer;

    return 0;
}

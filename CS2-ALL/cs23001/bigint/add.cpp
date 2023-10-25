#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main()
{
    std::ifstream in;       // Define input stream
    in.open("data1-1.txt"); // Open a file
    if (!in)
    { // Make sure file opened correctly
        std::cout << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    bigint bi, be, result;
    in >> bi >> be;

    while(!in.eof()){      
        std::cout << "bi " << bi << std::endl;
        std::cout << std::endl;
        std::cout << "be " << be << std::endl;

        result = bi + be;
        std::cout << std::endl;
        std::cout << "result "<< result << std::endl;
        std::cout << std::endl;
        in >> bi >> be;
    }

    in.close();
    return 0;
}

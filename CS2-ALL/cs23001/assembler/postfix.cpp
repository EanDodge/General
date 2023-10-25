#include "utilities.hpp"
#include <ostream>
#include <iostream>
#include <fstream>

int main(int argc, char** argv){
    std::ifstream in(argv[1]);

    if(!in){
        std::cout<< "Not there buddy"<<std::endl;
        exit(0);
    }
    if(argc > 2){
        std::ofstream out(argv[argc-1]);
        printInfix(out,in);
        }
    
    else{
        printInfix(std::cout,in);
    }
}


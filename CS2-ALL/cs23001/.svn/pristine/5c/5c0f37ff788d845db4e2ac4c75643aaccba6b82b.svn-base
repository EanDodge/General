#include"string.hpp"
#include<iostream>
#include<cassert>

void testCopy(const String &copy){
    std::cout<<"CALLED COPY CTOR"<<std::endl;
    std::cout<<"copy == "<< copy << std::endl;
    std::cout<<"DESTUCTING COPY"<<std::endl;
}

int main(){
    {
        String B("hello");
        std::cout<<"I am going to copy B"<<std::endl;
        testCopy(B);
    }
    {
        String B("I will be copied");
        std::cout<<"I am going to copy B"<<std::endl;
        testCopy(B);
    }
    {
        String B("");
        std::cout<<"I am going to copy B"<<std::endl;
        testCopy(B);
    }
}

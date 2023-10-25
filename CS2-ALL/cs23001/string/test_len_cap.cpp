#include<iostream>
#include<cassert>
#include"string.hpp"


int main(){
    {
        String one("ejbcuefucbeoichbeouceb rocuhrvecouervcouercveroihc c");
        int len = one.length();
        assert(len == 52);
        std::cout<<"cap is: "<< one.capacity()<<std::endl;
    
    }
    {
        String one;
        int len = one.length();
        assert(len == 0);
    }
    {
        String one("HquSm9I1qAHqBQLaKuicw9jkeU0nDo8s6TbAfds9uqU6e9h4O6HINzjZPYxl8QlVmd6QBvy7w5vdW2jz4fMM4c7pltSpdu9oZtWQLazg0XEP2sIrUcp9As0qHxlvO2ovLcQass1I9nRtFYPh5AuV0yDy2Y1l2seMhSEEBcuP3JncRWi4hgIoWmnmNVYo42xwrt0QYdJMEdmLBr9wXHXFuH68yLdpcSuW7y6TdZ3TkodJaiTu44W23mhONz54I80M");
        int len = one.length();
        assert(len == 256);
    }
    {
        String one("ejbcuefucbeoichbeouceb");
        int len = one.length();
        assert(len == 22);
    }
    {
        String one("I am tired of these tests cases :)");
        int len = one.length();
        assert(len == 34);
    }
}


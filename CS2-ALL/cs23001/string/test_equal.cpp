#include<iostream>
#include<cassert>
#include"string.hpp"


int main(){
    {
        String one("hello");
        String two("hello");
        bool flag = one == two;
        assert(flag == true);
    }
    {
        String one("hello");
        String two("hello");
        if(one == two)
            std::cout<<"true"<<std::endl;
        two[2] = '2';
        if(one != two)
            std::cout<<"not equal"<<std::endl;
    }
    {
        String one("hello9");
        String two("hello");
        bool flag = one == two;
        assert(flag == false);
    }
    {
        const char ch[6] = "hello";
        String two("hello");
        bool flag = ch == two;
        assert(flag == true);
    }
    {
        const char ch[7] = "hello!";
        String two("hello");
        bool flag = ch == two;
        assert(flag == false);
    }
    {
        char ch = 'h';
        String two('h');
        bool flag = ch == two;
        assert(flag == true);
    }
    {
        char ch = 'h';
        String two("he");
        bool flag = ch == two;
        assert(flag == false);
    }
    {
        String one("hello9");
        String two("hello");
        bool flag = one != two;
        assert(flag == true);
    }
    {
        String one("hello");
        String two("hello");
        bool flag = one != two;
        assert(flag == false);
    }
}


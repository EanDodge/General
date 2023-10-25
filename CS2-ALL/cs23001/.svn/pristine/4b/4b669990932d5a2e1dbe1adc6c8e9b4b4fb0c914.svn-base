#include<iostream>
#include<cassert>
#include"string.hpp"


int main(){
    {
        String one("1234");
        std::cout<<one[0]<<std::endl;
        assert(one[0] == '1');
        std::cout<<one[3]<<std::endl;
        assert(one[3]=='4');
    }
    
    {
        String one("3210");
        std::cout<<one[2]<<std::endl;
        assert(one[2]=='1');
    }
    {
        String one("Hello");
        std::cout<<one[2]<<std::endl;
        assert(one[2]=='l');
        assert(one[1]=='e');
        for(int i = 0; i < one.length(); ++i)
            std::cout<<one[i];
        std::cout<<std::endl;
    }
    {
        String one("Howdy");
        one[0]='p';
        assert(one[0]=='p');
    }
    {
        String one("Howdy");
        one[1]='p';
        assert(one[1]=='p');
    }
    {
        String one("Howdy, how was your day partner?  ");
        one[32]='p';
        assert(one[32]=='p');
    }
    {
        String one("Howdy, how was your day partner?");
        one[1]='p';
        assert(one[1]=='p');
        for(int i = 0; i < one.length(); ++i)
            one[i]= 'p';
        std::cout<<one.length()<<std::endl;
        assert(one[4]=='p');
    }
}


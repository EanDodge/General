#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
    {
        String one('T');
        assert(one == "T");
    }
    {
        String one('1');
        assert(one == "1");
    }
    {
        String one('&');
        assert(one == "&");
    }
    {
        String one('+');
        assert(one == "+");
    }
}


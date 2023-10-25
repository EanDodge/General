#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
    {
        String one("sup");
        int result;
        result = one.findch(0,'u');
        assert(result ==1 );

    }
    {
        String one("Howdy There Partner");
        int result;
        result = one.findch(6,' ');
        assert(result ==11 );
    }
    {
        String one(" ");
        int result;
        result = one.findch(0,' ');
        assert(result ==0);
    }
    {
        String one("Im listning to an awesome song right now");
        int result;
        result = one.findch(24,'o');
        assert(result ==27 );
    }
    {
        String one;
        int result;
        result = one.findch(0,' ');
        assert(result == -1);
    }
}


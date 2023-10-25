#include<iostream>
#include<cassert>
#include"string.hpp"


int main(){
    {
        String one("hello");
        String two("sup");
        bool flag = one<two;
        assert(flag == true);
    }
    {
        String one("sup");
        String two("hello");
        bool flag = one < two;
        assert(flag == false);
    }
    {
        const char ch[2] = "a";
        String one("ab");
        bool flag = ch < one;
        assert(flag == true);
    }
    {
        const char ch[3] = "ab";
        String one("a");
        bool flag = ch < one;
        assert(flag == false);
    }
    {
        char ch = 'a';
        String one('b');
        bool flag = ch< one;
        assert(flag == true);
    }
    {
        char ch = 'b';
        String one('a');
        bool flag = ch< one;
        assert(flag == false);
    }
    {
        String one("sup");
        String two("hello");
        bool flag = one <= two;
        assert(flag == false);
    }
    {
        String one("hello");
        String two("hello");
        bool flag = one <= two;
        assert(flag == true);
    }
    {
        String one("hell");
        String two("hello");
        bool flag = one <= two;
        assert(flag == true);
    }
    {
        String one("sup");
        String two("hello");
        bool flag = one > two;
        assert(flag == true);
    }
    {
        String one("hello");
        String two("sup");
        bool flag = one > two;
        assert(flag == false);
    }
    {
        String one("hello");
        String two("hello");
        bool flag = one >= two;
        assert(flag == true);
    }
    {
        String one("sup");
        String two("hello");
        bool flag = one >= two;
        assert(flag == false);
    }
    
}


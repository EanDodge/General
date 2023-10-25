#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
{
    String one("Hello World");
    String two;
    two = one.substr(1,5);
    assert(two == "ello ");
}
{
    String one("Hello World!!");
    String two;
    two = one.substr(10,12);
    assert(two == "d!!");
}
{
    String one("strings are cool");
    String two;
    two = one.substr(12,15);
    assert(two == "cool");
}
{
    String one(" ");
    String two;
    two = one.substr(0,0);
    assert(two == " ");
}
{
    String one("World");
    String two;
    two = one.substr(0,4);
    assert(two == "World");
    assert(one == two);
}
}


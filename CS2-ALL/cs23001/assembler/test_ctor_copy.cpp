#include<iostream>
#include"stack.hpp"
#include"../string/string.hpp"
#include<cassert>



int main() {
    stack<int> S;
    assert(S.empty());
    copyctor(S);
    stack<String> ch;
    assert(ch.empty());
    copyctor(ch);
    stack<char> st;
    assert(st.empty());
    copyctor(st);
    stack<double> dou;
    assert(dou.empty());
    copyctor(dou);
    std::cout<<"Done testing copy ctor"<<std::endl;
}
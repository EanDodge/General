#include<iostream>
#include"stack.hpp"
#include"../string/string.hpp"
#include<cassert>

int main(){
    {
    stack<String> S;
    assert(S.empty());

    stack<int> I;
    assert(I.empty());

    stack<double> D;
    assert(D.empty());

    stack<float> F;
    assert(F.empty());

    stack<char> C;
    assert(C.empty());

    stack<String> str;
    assert(str.empty());
    
    std::cout<<"all types have been implemented"<<std::endl;
    }

    std::cout<< " Done testing defualt ctor"<<std::endl;
}

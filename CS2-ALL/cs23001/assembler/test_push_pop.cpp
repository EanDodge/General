#include<iostream>
#include"stack.hpp"
#include"../string/string.hpp"
#include<cassert>

int main(){
    {
        stack<int> S;
        S.push(5);
        assert(S.top() == 5);
        std::cout<<"this should be 5 - "<<S.pop()<<std::endl;
        assert(S.empty());
    }
    {
        stack<char> S;
        S.push('H');
        assert(S.top() == 'H');
        std::cout<<"this should be H - "<<S.pop() << std::endl;
        assert(S.empty());
    }
    {
        stack<double> S;
        S.push(5.2);
        assert(S.top() == 5.2);
        std::cout<<"this should be 5.2 - "<<S.pop() << std::endl;
        assert(S.empty());
    }
    {
        stack<String> S;
        S.push("hello");
        assert(S.top() == "hello");
        std::cout<<"this should be 'hello' - "<<S.pop() <<std::endl;
        assert(S.empty());
    }
    {
        stack<int> S;
        for(int i = 0; i < 100; ++i)
            S.push(6074627);
        assert(S.top() == 6074627);
        while(!S.empty())
            S.pop();
        std::cout<<"this should be 0 - "<<"0"<<std::endl;
        assert(S.empty());
    }

    std::cout<< "Done testing push-pop"<<std::endl;
}

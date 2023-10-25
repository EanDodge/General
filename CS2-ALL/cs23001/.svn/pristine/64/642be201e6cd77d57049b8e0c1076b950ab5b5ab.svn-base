#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector>

int main()
{
    {
        String A("ab c");
        std::vector<String> S;
        S = A.split(' ');
        assert(S[0] == "ab");
        assert(S[1] == "c");
    }
    {
        String A;
        std::vector<String> S;
        S = A.split(' ');
        assert(S[0] == "");
    }
    {
        String A("hello how are you doing today, because i am doing great");
        std::vector<String> S;
        S = A.split(' ');
        assert(S[0] == "hello");
        std::cout<<"PRINTING THE VECTOR: ";
        for(auto i = 0; i < S.size(); ++i){
            std::cout << S[i] << std::endl;
        }
        //std::cout<<"debug"<<std::endl;
    }
    {
        
        String A("123-456-7890");
        std::vector<String> S;
        S = A.split('-');
        assert(S[0] == "123");    
            //std::cout<<"debug"<<std::endl;
    }
    {
        String A("123--456");
        std::vector<String> S;
        S = A.split('-');
        assert(S[1] == "");
        //std::cout<<"debug"<<std::endl;
    }
    {
        String A("hello how are you doing today, because i am doing great hehe fhfhd hehe hello word go  to there i love computer science this is a word that i am  writing");
        std::vector<String> S;
        S = A.split(' ');
        std::cout<<S.size()<<std::endl;
        assert(S[0] == "hello");
        //std::cout<<"debug"<<std::endl;
    }
    {
        String A("hello how are you doing today, because i am doing great");
        std::vector<String> S;
        S = A.split(',');
        assert(S[1] == " because i am doing great");
        assert(S.size() == 2);
        //std::cout<<"debug"<<std::endl;
    }
}

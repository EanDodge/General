#include "logger.hpp"


void makePrint(Logger* rhs);

void read(Logger* rhs);

int main(){
    srand(time(nullptr));
    Logger* v1 = Logger::instance();

    v1->report("HELPPPPP!!!!!!!!!!!!!!!!!!!!!");
    makePrint(v1);
    read(v1);
}

void makePrint(Logger* rhs){
    string result;
    for(int i = 0; i < 80; ++i){
        char ran = (char)rand() %26 + 97;
        result.push_back(ran);
    }
    rhs->report(result);
}

void read(Logger* rhs){
    ifstream in ("nesterenko.txt");

    string result;
    string temp;
    while(in >> temp){
        result += temp;
    }

    rhs->report(result);
}

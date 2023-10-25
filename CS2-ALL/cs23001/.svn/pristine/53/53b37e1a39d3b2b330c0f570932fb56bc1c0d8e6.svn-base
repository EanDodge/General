//fileio example program
//Ean Dodge
//cs23001
#include<fstream>
#include<iostream>
#include <stdlib.h>

void findNum();

int main() {
    std::ifstream in;
    in.open("fileio-text.txt");

    if (in.fail())
        exit(1);
    else {
        char ch;
        in.get(ch);
        while (!in.eof()) {
            if (ch != ' ') {
                std::cout << ch;
            }
            else
                std::cout << std::endl;
            in.get(ch);
        }
    }
    in.close();
    findNum();
    }


void findNum() {
    std::ifstream in;
    in.open("fileio-data-1.txt");

    if (in.fail()) {
        std::cout << "could not open" << std::endl;
        exit(1);
    }
    else {
        char array1[100];
        char array2[100];
        for (int i = 0; i < 100; ++i) {
            array1[i] = 0;
            array2[i] = 0;
        }
        char ch;
        int i = 0, j = 0, number1, number2;
        in >> ch;
        while (ch != ';') {
            array1[i] = ch;
            in >> ch;
            ++i;
        }
        number1 = atoi(array1);
        in >> ch;
        while (ch != ';') {
            array2[j] = ch;
            in >> ch;
            ++i;
        }
        number2 = atoi(array2);
        std::cout << number1 + number2;

    }
    
        
}

//
//  STL examples
//
//  Created by Jonathan Maletic
//  Copyright 2023 Kent State University. All rights reserved.
//  Spring 2023
//
//  Compile with:
//  clang++ -std=c++11 -Wall stl-examples.cpp


#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>



int main() 
{
    //vector
    {
        std::vector<int> v;
        std::cout << "The initial size of v is: " << v.size()
                  << "\nThe initial capacity of v is: " << v.capacity();
        v.push_back( 2 );  v.push_back( 3 );  v.push_back( 4 );
        std::cout << "\nThe size of v is: " << v.size()
                  << "\nThe capacity of v is: " << v.capacity();

        std::cout << "\n\nContents of vector v a using array notation: ";
        for (int i=0; i<v.size(); ++i) {
            std::cout << v[i] << " ";
        }

        std::cout << "\nContents of vector v using iterator notation: ";
        for (std::vector<int>::const_iterator p1 = v.begin();
             p1 != v.end(); p1++) {
            std::cout << *p1 << " ";
        }

        std::cout << "\nReversed contents of vector v: ";
        std::vector<int>::reverse_iterator p2;
        for (p2 = v.rbegin(); p2 != v.rend(); ++p2) {
            std::cout << *p2 << " ";
        }

        std::cout << std::endl;
    }

    //List
    {
        std::list<int> lst;
        lst.push_back(10); lst.push_back(20);
        lst.push_back(30); lst.push_back(40);
        for (std::list<int>::const_iterator i = lst.begin(); i != lst.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;

        std::list<int>::iterator ptr = lst.begin();
        ++ptr; ++ptr;
        lst.insert(ptr, 100);
        for (std::list<int>::const_iterator i = lst.begin(); i != lst.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;

        std::list<char> lst2;
        lst2.push_back('a'); lst2.push_back('b');
        lst2.push_back('c'); lst2.push_back('d');
        for(std::list<char>::const_iterator i = lst2.begin(); i != lst2.end(); ++i){
            std::cout<< *i << " ";
        }
        std::cout<<std::endl;
        std::list<char>::iterator ptr2 = lst2.begin();
        ++ptr2; ++ptr2; ++ptr2; ++ptr2;
        lst2.insert(ptr2, 'e');

        for(std::list<char>::const_iterator i = lst2.begin(); i != lst2.end(); ++i){
            std::cout << *i << " ";
        }
        std::cout<<std::endl;
    }


    //Map
    {
        std::map<std::string, int> tbl;
        tbl["joe"] += 1;
        tbl["joe"] += 1;
        tbl["sue"] += 1;
        tbl["jon"] += 1;
        tbl["sue"] += 1;
        tbl["fred"] += 1;

        for(std::map<std::string, int>::const_iterator i = tbl.begin(); i != tbl.end(); ++i) {
            std::cout << i->first << " " << i->second << std::endl;
        }
        std::map<char, std::string> tbl2;
        tbl2['a'] += "Ean";
        tbl2['b'] += "Brandon";
        tbl2['c'] += "Bolts";
        tbl2['d'] += "Alex";

        for(std::map<char, std::string>::const_iterator i = tbl2.begin(); i != tbl2.end(); ++i){
            std::cout << i->first << " " << i->second << std::endl;
        }

    }

    //Set
    {
        typedef std::set<double, std::less<double>> double_set;
        const int SIZE = 5;
        double a[ SIZE ] = { 2.1, 4.2, 9.5, 2.1, 3.7 };
        double_set doubleSet( a, a + SIZE );;
        std::ostream_iterator<double> output( std::cout, " " );
        std::cout << "doubleSet contains: ";
        std::copy( doubleSet.begin(), doubleSet.end(), output );

        std::pair<double_set::const_iterator, bool> p;
        p = doubleSet.insert( 13.8 ); // value not in set
        std::cout << '\n' << *( p.first )
        << ( p.second ? " was" : " was not" ) << " inserted";
        std::cout << "\ndoubleSet contains: ";

        std::copy(doubleSet.begin(), doubleSet.end(), output);
        p = doubleSet.insert( 9.5 );  // value already in set
        std::cout << '\n' << *( p.first )
        << ( p.second ? " was" : " was not" ) << " inserted";
        std::cout << "\ndoubleSet contains: ";

        std::copy(doubleSet.begin(), doubleSet.end(), output);
        std::cout << std::endl;
    }

    return 0;
}






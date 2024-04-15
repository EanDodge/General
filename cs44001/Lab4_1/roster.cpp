// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;

// reading a list from a fileName
void readRoster(list<list<string>>& roster, string fileName);  

// printing a list out
void printRoster(const list<list<string>>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ 
      cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" 
      << endl;
      exit(1);
   }

   // vector of courses of students
   list<list<string>> courseStudents; 
   //vector <string> courseList{"cs1", "cs2", "cs3", "cs4"};
   
   for(int i=1; i < argc-1; ++i){
      list<list<string>> roster;
      readRoster(courseStudents, argv[i]);  
      cout << "\n\n" << argv[i] << "\n\n";  
      printRoster(courseStudents);
      //courseStudents.push_back(move(roster));
   }
   
   // reading in dropouts
   list<list<string>> dropouts; 
   readRoster(dropouts, argv[argc-1]); 
   cout << "\n\n dropouts \n";
   printRoster(dropouts);

   // master list of students
   list<list<string>> allStudents;  
   for(int i=1; i < argc; ++i){
      list<list<string>> roster;
      readRoster(allStudents, argv[i]);  
      cout << "\n\n" << argv[i] << "\n\n";  
      //printRoster(allStudents);
      //courseStudents.push_back(move(roster));
   }

   //for(auto& lst : courseStudents) 
     //allStudents.splice(allStudents.end(), lst);

   cout << "\n\n all students unsorted \n"; 
           printRoster(courseStudents);

   
   // sorting master list
   courseStudents.sort();
   cout << "\n\n all students sorted \n"; 
   printRoster(courseStudents);

   
   // eliminating duplicates
   courseStudents.unique(); 
   cout << "\n\n all students, duplicates removed \n"; 
   printRoster(courseStudents);
   for( auto itr = allStudents.begin(); itr != allStudents.end();){
      if(itr->back() == "dropouts")
         itr = allStudents.erase(itr);
      else
         ++itr;
   }
   // removing individual dropouts
   // for (auto itr= courseStudents.begin(); itr !=  courseStudents.end();){
   //       for (const auto& str : dropouts)  {
   //          if (itr->front() == str.front()){
   //          itr = courseStudents.erase(itr);
   //          }
   //          else
   //          ++itr;
   //    }
   // }

   cout << "\n\n all students, dropouts removed \n"; 
   allStudents.sort();
   printRoster(allStudents);
   
}

// reading in a file of names into a list of strings
void readRoster(list<list<string>>& roster, string fileName){
   ifstream course(fileName);
   string classEntry = fileName;
   size_t position = classEntry.find_first_of(".");
   if(position != string::npos){
      classEntry = classEntry.substr(0,position);   //grabbing csx
   }
   
   string first, last;
   while(course >> first >> last){
      list<string> lst;
      //cout<<"in while loop"<<endl;
      string name = (first + ' ' + last);
      
      
      bool found = false;
      
      for (auto& entry : roster){
         //cout<<"in for"<<endl;
         if (entry.front() == name){
            entry.push_back(classEntry);
            //cout<<"front == name"<<endl;
            found = true;
         }
      }
         if(!found){
            //cout << "not found"<<endl;
            //cout << name << endl;
            lst.push_back(name);
            lst.push_back(classEntry);
            roster.push_back(lst);
         }
         // for(auto itr : entry){
         //    cout << itr << " ";
         // }
         //cout << "end of entry" << endl;
      
   }
   course.close();
}

// printing a list out
void printRoster(const list<list<string>>& roster){
   for(const auto& itr : roster){
      for ( const auto& str : itr){
         cout << str << " ";
      }
      cout<<endl;
   }
      
}


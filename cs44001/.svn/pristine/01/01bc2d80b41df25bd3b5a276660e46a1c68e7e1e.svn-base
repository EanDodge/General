// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

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


class Student{
public:
   Student(string name, string classEntry) { 
      entry_.push_back(name);
      entry_.push_back(classEntry);
   }
   // move constructor, not really needed, generated automatically
   Student(Student && org) noexcept:
      entry_(move(org.entry_))
   {};

   string getFront(){return entry_.front();};
   string getBack() {return entry_.back();};
   void add(string str){entry_.push_back(str);};
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
   void print() const {for(auto itr: entry_) cout<<itr<<" ";cout<<endl;}

    // needed for unique() and for remove()
   friend bool operator== (Student left, Student right){
      return left.entry_.front() == right.entry_.front();
   }

   // needed for sort()
   friend bool operator< (Student left, Student right){
      return left.entry_.front() < right.entry_.front();
   }
private:
   list<string> entry_;

};




// reading a list from a fileName
void readRoster(list<Student>& roster, string fileName);  
// printing a list out
void printRoster(const list<Student>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   // vector of courses of students
   list<Student> courseStudents; 

   for(int i=1; i < argc-1; ++i){
      //list<Student> roster;
      readRoster(courseStudents, argv[i]);  
      cout << "\n\n" << argv[i] << "\n";  
      printRoster(courseStudents);
      //courseStudents.push_back(move(roster)); 
   }


   // reading in dropouts
   list<Student> dropouts; 
   readRoster(dropouts, argv[argc-1]); 
   cout << "\n\n dropouts \n"; printRoster(dropouts);

   list<Student> allStudents;  // master list of students
 
   // for(auto& lst : courseStudents) 
   //   allStudents.splice(allStudents.end(),lst);
   for(int i=1; i < argc; ++i){
      //list<Student> roster;
      readRoster(allStudents, argv[i]);  
      //cout << "\n\n" << argv[i] << "\n";  
      //printRoster(allStudents);
      //courseStudents.push_back(move(roster)); 
   }
   cout << "\n\n all students unsorted \n"; 
           printRoster(courseStudents);

   courseStudents.sort(); // sorting master list
   cout << "\n\n all students sorted \n"; printRoster(courseStudents);

   courseStudents.unique(); // eliminating duplicates
   cout << "\n\n all students, duplicates removed \n"; printRoster(courseStudents);
   allStudents.sort();
   for( auto itr = allStudents.begin(); itr != allStudents.end();){
      if(itr->getBack() == "dropouts")
         itr = allStudents.erase(itr);
      else
         ++itr;
   }
   cout << "\n\n all students, dropouts removed \n"; printRoster(allStudents);

}


void readRoster(list<Student>& roster, string fileName){
   ifstream course(fileName);
   string classEntry = fileName;
   size_t position = classEntry.find_first_of(".");
   if(position != string::npos){
      classEntry = classEntry.substr(0,position);   //grabbing csx
   }
   
   string first, last;
   while(course >> first >> last){
      //cout<<"in while loop"<<endl;
      string name = (first + ' ' + last);
      
      
      bool found = false;
      
      for (auto& entry : roster){
         //cout<<"in for"<<endl;
         if (entry.getFront() == name){
            entry.add(classEntry);
            //cout<<"front == name"<<endl;
            found = true;
         }
      }
         if(!found){
            //cout << "not found"<<endl;
            //cout << name << endl;
            Student lst(name, classEntry);
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
void printRoster(const list<Student>& roster){
   for(const auto& student : roster)
      student.print();
}



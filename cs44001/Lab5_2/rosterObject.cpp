// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector; using std::set;
using std::cout; using std::endl;
using std::move; using std::map;


class Student{
public:
   Student(string name) { 
      name_ = (name);
   }
   // move constructor, not really needed, generated automatically
   Student(Student && org) noexcept:
      name_(move(org.name_))
   {};

   //string getFront(){return entry_.front();};
   //string getBack() {return entry_.back();};
   //void add(string str){entry_.push_back(str);};
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
   void print() const {cout << name_ << endl;}

    // needed for unique() and for remove()
   friend bool operator== (Student left, Student right){
      return left.name_ == right.name_;
   }

   // needed for sort()
   friend bool operator< (Student left, Student right){
      return left.name_ < right.name_;
   }
private:
   string name_;

};




// reading a list from a fileName
void readRoster(set<Student>& roster, string fileName);  
// printing a list out
void printRoster(const set<Student> roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   set<Student> courseStudents;
   // vector of courses of students
   //list<Student> courseStudents; 

   for(int i=1; i < argc-1; ++i){
      //list<Student> roster;
      readRoster(courseStudents, argv[i]);  
      cout << "\n\n" << argv[i] << "\n";  
      printRoster(courseStudents);
      //courseStudents.push_back(move(roster)); 
   }


   // reading in dropouts
   set<Student> dropouts; 
   readRoster(dropouts, argv[argc-1]); 
   cout << "\n\n dropouts \n"; printRoster(dropouts);

   set<Student> allStudents;  // master list of students
   
 
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

   //courseStudents.sort(); // sorting master list
   cout << "\n\n all students sorted \n"; printRoster(courseStudents);

   //courseStudents.unique(); // eliminating duplicates
   // cout << "\n\n all students, duplicates removed \n"; printRoster(courseStudents);
   // allStudents.sort();
   // for( auto itr: allStudents){
   //    if(itr.second.back() == "dropouts")
   //       allStudents.erase(itr.first);
   //    else
   //       ++itr;
   // }//
   for (auto dropout : dropouts){
      const Student& student = dropout;
      allStudents.erase(student);
   }
   cout << "\n\n all students, dropouts removed \n"; printRoster(allStudents);

}


void readRoster(set<Student>& roster, string fileName){
   ifstream course(fileName);
   //string classEntry = fileName;
   //size_t position = classEntry.find_first_of(".");
   // if(position != string::npos){
   //    classEntry = classEntry.substr(0,position);   //grabbing csx
   // }
   
   string first, last;
   while(course >> first >> last){
      //cout<<"in while loop"<<endl;
      Student name(first+" "+last);
      // auto it = roster.find(name);
      // if(it != roster.end())
      //    it->second.push_back(classEntry);
      // else{
         list<string> tmp;
         //tmp.push_back(classEntry);
         //roster[name] = tmp;
         roster.insert(name);
      //}
      
      bool found = false;
      
      // for (auto& entry : roster){
      //    //cout<<"in for"<<endl;
      //    if (entry.getFront() == name){
      //       entry.add(classEntry);
      //       //cout<<"front == name"<<endl;
      //       found = true;
      //    }
      // }
         // if(!found){
         //    //cout << "not found"<<endl;
         //    //cout << name << endl;
         //    Student lst(name, classEntry);
         //    roster.push_back(lst);
         // }
         // for(auto itr : entry){
         //    cout << itr << " ";
         // }
         //cout << "end of entry" << endl;
      
   }
   course.close();
}

// printing a list out
void printRoster(const set<Student> roster){
   
   for(const auto& e: roster){
      e.print();
   }

}



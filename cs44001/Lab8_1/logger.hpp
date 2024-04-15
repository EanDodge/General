//Ean Dodge

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::cout; using std::endl;
using std::vector; using std::ofstream;
using std::string; using std::ifstream;

class Logger{
public:
   static Logger* instance(){
      static Logger s;
      return &s;
   }

    void report(const string& out){
        log_<< out;
    };

   

   Logger(const Logger&) = delete;
   Logger& operator=(const Logger&) = delete;

private:
   // copying and creation prohibited by clients
   Logger(){log_.open("log.txt", std::fstream::out | std::fstream::app);};
   // SingletonVect(const SingletonVect&){}
   // SingletonVect& operator=(const SingletonVect&){}

   ofstream log_; // payload   
};

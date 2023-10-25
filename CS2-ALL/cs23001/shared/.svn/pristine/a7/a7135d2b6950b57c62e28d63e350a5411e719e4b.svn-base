/*
Example of Command Line Interface
cli_io

*/

#include <string>
#include <iostream>
#include <fstream>

void get_word (std::istream& in, std::string& myWord){
  if (!in.eof())
  in>>myWord;
}    

void get_line (std::istream& in, std::string& myLine){
  getline(in, myLine);
}

int main(int argc, char *argv[]){
  char choice = argv [1][0];
  
  std::ifstream in (argv [2]);
  if ( !in.is_open() ){
    std::cout<<"Could not open file\n";
    return 1;
  }

  std::ofstream out (argv [3]);
  std::string destination;
  int count = 0;

  while (!in.eof()){
  switch (choice){
  case '1': 
      get_word(in, destination);
      if(!in.eof()){      
      out << destination<<"\n";
      ++count;
      }
      break;
  case '2':
      get_line(in, destination); 
      if (!in.eof()){
      out << destination<<"\n";
      ++count;
      }
      break;
  }
  }



  out<<"Number of times of execution is: "<<count<<"\n";
  
  in.close();
  in.close();
  return 0;
}

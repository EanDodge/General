// File:        cli.cpp
//
// Date:        Fall 2022
// Author:      Maletic
//
// Description: Basics of Command Line Interface (CLI)
//              aka Command Line Arguments
//

#include <iostream>
#include <fstream>

// int argc - (ARGument Count) Is the number of command-line arguments passed,
//   on the commmand line, by the user.  This includes the program name.
//   So if a value is passed to a program (prog input.txt), value of argc is 2,
//   one the program name (prog) and argument (input.txt)
//
// char *argv[] (ARGument Vector) is an array of character arrays containing
//    each of the arguments on the command line, including the program name.
// If argc is greater than zero,the array elements from argv[0] to argv[argc-1]
//    will contain a pointer to a char (i.e., null terminating char[])
//    argv[0] is the name of the program, argv[1] is the first argument,
//    argv[2] is the second argument.
//
// When using command line arguments, error checking must be done to ensure the
//    program interface behaves correctly.   Check correct number of arguments,
//    and any options.
//


//The following program reads in a input and output file name.
// Run using something like:  the input file must exist.
// ./a.out output1.txt temp.txt

int main(int argc, char *argv[]) {
    if (argc != 3) {      // Error if there are not 3 things on the command line
        std::cerr << "Error: Usage is " << std::endl;
        std::cerr << argv[0] << " input-file output-file " << std::endl;
        exit(1);         // Exit with error
    }

    std::ifstream in(argv[1]);     // Open file, quit if open fails
    if (!in) {
        std::cerr << "Error: Can not open " << argv[1] << std::endl;
        exit(1);
    }
    in.close();

    std::ofstream out(argv[2]);
    out << "Output file" << std::endl;
    out.close();

    return 0;
}

// Ean Dodge
// kent state
// CS3 with Dr. Nesterenko
// Lab1

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


int main(int argc, char *argv[])
{
    const int offsetSingle = 5;
    const int offsetTens = 6;
    const int offsetHund = 7;
    int lineNumber = 1;
    ifstream fin1;
    ifstream fin2;
    fin1.open(argv[1]); // open both files
    fin2.open(argv[2]);
    const string fileName = argv[1];
    const int fileNameLength = fileName.length(); // get length, this is for printing carrot

    if (argc < 3)
    {
        cout << "error, not enough arguments in command line" << endl;
        exit(1);
    }

    if (fin1.fail())
    { // made to exit program if file 1 not found
        cout << "failed to open file 1" << endl;
        exit(1);
    }

    if (fin2.fail())
    { // made to exit program if file 2 not found
        cout << "failed to open file 2" << endl;
        exit(1);
    }

    else
    {//while its not the end of either file
        while (!fin1.eof() || !fin2.eof())
        {
            string line1;
            string line2;

            // get line will get the line from the file if its not the end of file
            if (!fin1.eof())
                getline(fin1, line1);
            else 
                line1 = "";

            if (!fin2.eof())
                getline(fin2, line2);
            else
                line2 = "";

            //ternary operator to find how many indexies to go through
            int len = line1.length() > line2.length() ? line1.length() : line2.length(); 

            bool good = true;
            //initilize i to 0 for indexing varible
            int i = 0;
            //while the charcters are the same and its not the end of the longest string
            while (good && i < len)
            {
                if (line1[i] != line2[i])
                { //characters are different
                    int j = 0;
                    j = i;
                    //boolean says different characters
                    good = false;

                    if (lineNumber < 10)
                    {//j is the length of chacters till the difference happens
                        j += offsetSingle;  //offset is 5 characters to offset for ": 9: "
                        j += fileNameLength;//this offsets for the file name

                        string spaceString(j, ' '); //spaces include file name, offset, and j

                        cout << argv[1] << ": " << lineNumber << ": " << line1 << endl; //print lines
                        cout << argv[2] << ": " << lineNumber << ": " << line2 << endl;
                        cout << spaceString << "^" << endl; //print the carrot
                    }

                    else if (lineNumber > 10 && lineNumber < 100)
                    {
                        j += offsetTens;           //j += offset += filenamelength;
                        j += fileNameLength;       

                        string spaceString(j, ' ');
                        
                        cout << argv[1] << ": " << lineNumber << ": " << line1 << endl;
                        cout << argv[2] << ": " << lineNumber << ": " << line2 << endl;
                        cout << spaceString << "^" << endl;
                    }
                    else 
                    {
                        j += offsetHund;
                        j += fileNameLength;       

                        string spaceString(j, ' ');
                        
                        cout << argv[1] << ": " << lineNumber << ": " << line1 << endl;
                        cout << argv[2] << ": " << lineNumber << ": " << line2 << endl;
                        cout << spaceString << "^" << endl;
                    }
                }
                ++i; //increment the index of the char array
            }
            ++lineNumber; // add one to the line number, for printing purposes
        }
    }
}

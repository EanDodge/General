//////////////////////////////////////////////
// Commenting pre and post conditions
// J. Maletic KSU 2020
//
// ASSERT:     Assertion, a statement that is true at this point in the program.
// REQUIRES:   Precondition, a statement that needs to be true before
//             the function is executed.
// ENSURES:    Postcondition, an assertion that is true after a function
//             is executed.
// INV:        Invariant, a statement that is always ture within a given scope.
// CLASS INV:  Holds true for all objects of a class.
// LOOP INV:   Holds true for every interation of a loop.
// GLOBAL INV: Is always true for the program.
// 
#include <iostream>

//REQUIRES:  assigned(key && tbl[0,..size-1]) && (size >= 0)
//ENSURES:   (RETVAL == i where tbl[i] == key) ||
//           (RETVAL == -1 where i == size)
int search(const int tbl[], int key, int size) {
    //ASSERT (size >= 0) && (sizeof(tbl) == size)
    int i = 0;
    //ASSERT (size >= 0) && (sizeof(tbl) == size) && i == 0
    while (i < size){
    //LOOP INV: (key != tbl[0,..,i]) && (i <= size)
        if (tbl[i] == key) {
            //ASSERT (tbl[i] == key) && (i < size)
            return i;
        }
        //ASSERT (key != tbl[0,..,i]) && (i < size)
        ++i;
        //ASSERT (key != tbl[0,..,i-1]) && (i <= size)

    }
    //ASSERT key != tbl[0,..,size-1]

    return -1;
}


int main() {
    int a[10] = {2,4,5,6,7,8,9,20,3,12};

    std::cout << search(a,9,10) << std::endl;
    std::cout << search(a,99,10) << std::endl;
    std::cout << std::endl << "done" << std::endl;
}

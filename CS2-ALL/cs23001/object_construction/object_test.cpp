#include <iostream>
#include "object_construction.hpp"

void value(const Wall a)
{
    
    std::cout << "########## value called ###########" << std::endl;
}
void reference(const Wall &a)
{
    std::cout << "############# reference called #########" << std::endl;
}
int main()
{
    Wall example;
    int size = 5, size2=10;
    int arr[size], arr2[size2];
    Wall one(arr, size);
    Wall two(arr2, size2);

    value(one);
    reference(two);
    one = two;
}
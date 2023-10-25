#include <iostream>
#include "object_construction.hpp"

Wall::Wall()
{
    size = 0;
    maze = new int[size];
    std::cout<<"########default ctor########"<<std::endl;
}

Wall::Wall(const int arr[], const int num)
{ // constructor
    size = num;
    maze = new int[size];
    for (int j = 0; j < num; ++j)
    {
        maze[j] = arr[j];
    }
    std::cout<<"#######constructor called######"<<std::endl;
}

Wall::~Wall()
{ // destructor

    delete[] maze;
    std::cout<<"###########detructor############"<<std::endl;
}

Wall::Wall(const Wall &rhs)//copy ctor
{

    size = rhs.size;
    maze = new int[size];
    for (int i = 0; i < size; ++i)
        maze[i] = rhs.maze[i];
    std::cout<<"##########copy ctor#############"<<std::endl;
}

Wall &Wall::operator=(const Wall &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    else
    {
        size = rhs.size;
        delete[] maze;
        maze = new int[size];
        for (int i = 0; i < size; ++i)
            maze[i] = rhs.maze[i];
    }
    return *this;
    std::cout << this << ": I am " << rhs << " and i am " << size << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Wall &rhs)
{
    for (int j = 0; j < rhs.size; ++j)
        out << rhs.maze[j];
    return out;
}
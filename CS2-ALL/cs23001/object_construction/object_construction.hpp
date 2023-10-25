#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>


class Wall
{
public:
    Wall();
    Wall(const int[], const int);
    ~Wall();
    Wall(const Wall &);
    Wall &operator=(const Wall &);
    friend std::ostream &operator<<(std::ostream &, const Wall &);

private:
    int *maze;
    int size;
};

#endif
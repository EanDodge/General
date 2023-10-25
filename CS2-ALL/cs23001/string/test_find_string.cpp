#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    {
        String one("Hello World");
        String two("ll");
        int find;
        find = one.findstr(0, two);
        assert(find == 2);
        std::cout << find << std::endl;
    }
    {
        String one;
        String two("ll");
        int find;
        find = one.findstr(0, two);
        assert(find == -1);
        std::cout << find << std::endl;
    }
    {
        String one("Hello World");
        String two("eo");
        int find;
        find = one.findstr(0, two);
        assert(find == -1);
        std::cout << find << std::endl;
    }
    {
        String one("Hello World!!");
        String two("!");
        int find;
        find = one.findstr(0, two);
        assert(find == 11);
        std::cout << find << std::endl;
    }
    {
        String one("kjbci3rbc3ribc3icb3job3iuxb3ejxb3eyiydve3khdxb3e");
        String two("3ribc");
        int find;
        find = one.findstr(0, two);
        assert(find == 9);
        std::cout << find << std::endl;
    }
    {
        String one("I Love Computer Science!!");
        String two("I Love Computer Science!");
        int find;
        find = one.findstr(0, two);
        assert(find == 0);
        std::cout << find << std::endl;
    }
    {
        {String one("I Love Computer Science!!");
    String two("I Love Computer Science!!");
    int find;
    find = one.findstr(0, two);
    assert(find == 0);
    std::cout << find << std::endl;
}
}
{

    String one;
    String two;
    int find;
    find = one.findstr(0, two);
    assert(find == -1);
    std::cout << find << std::endl;
}
}

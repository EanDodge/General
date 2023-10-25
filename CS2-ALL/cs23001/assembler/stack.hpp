//
// File: stack.hpp
//
// Programmer: Ean Dodge
// Date:   4/10/2023    Spring 2023
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>
#include <new>
#include "../string/string.hpp"

template <typename T>
class Node
{
public:
    Node() : next(0){};
    Node(const T &item) : data(item), next(0){};

    T data;        // the data (element)
    Node<T> *next; // pointer to a Node
};

// CLASS INV:
//
template <typename T>
class stack
{
public:
    stack() : tos(0){};
    stack(const stack<T> &);
    ~stack();
    void swap(stack<T> &);
    stack<T> &operator=(stack<T> rhs)
    {
        swap(rhs);
        return *this;
    };

    bool empty() const { return tos == 0; };
    bool full() const;

    T    top() const
    {
        assert(!empty());
        return tos->data;
    };

    T pop();
    void push(const T &);

private:
    Node<T> *tos;
};

// push
//  requires: tos-> x1 -> x2 -> ...xn->0
//  ensures: tos-> item -> x1 -> x2 -> ...xn->0
template <typename T>
void stack<T>::push(const T &item)
{
    assert(!full());
    Node<T> *temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}
// pop
// requires: tos != 0 || tos -> x1 -> x2 -> ... xn->0
// ensures: tos-> x2 -> ... xn->0
template <typename T>
T stack<T>::pop()
{
    T result;
    assert(!empty());
    result = tos->data;
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}
//
template <typename T>
stack<T>::~stack()
{ // destructor
    Node<T> *temp = 0;
    while (tos != 0)
    {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
    //std::cout << "destructor activated" << std::endl;
}

template <typename T>
stack<T>::stack(const stack<T> &actual) : stack<T>()
{
    Node<T> *temp = actual.tos;
    Node<T> *bottom;
    while (temp != 0)
    {
        if (tos == 0)
        {
            tos = new Node<T>(temp->data);
            bottom = tos;
        }
        else
        {
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
    std::cout << "copy ctor activated" << std::endl;
}
template <typename T>
void stack<T>::swap(stack<T> &rhs)
{
    Node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const
{
    Node<T> *temp = new (std::nothrow) Node<T>();
    if (temp == 0)
        return true; // out of memory
    delete temp;
    return false;
}

template <typename T>
void copyctor(stack<T> S)
{
    S.empty();
    std::cout << "copy ctor used" << std::endl;
    std::cout << "destructing in " << std::endl
              << "3" << std::endl
              << "2" << std::endl
              << "1" << std::endl;
}

#endif

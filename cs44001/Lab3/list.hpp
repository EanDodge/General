// node class tempate used to contruct lists
// Mikhail Nesterenko
// 5/01/00

#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;
template <typename T>
class node;
template <typename T>
class Collection;

template <typename T>
bool equal(const Collection<T> &one, const Collection<T> &two);

template <typename T>
class Collection
{
public:
  Collection() : list_(nullptr){}
  Collection(const Collection<T> &);
  //~Collection();
  void swap(Collection<T> &);
  //Collection<T> &operator=(Collection<T> rhs)
  // {
  //   swap(rhs);
  //   return *this;
  // };
  void add(const T& item);
  void remove(const T &item);
  T last() const;
  void print();
  friend bool equal<T>(const Collection&, const Collection&);
private:
  node<T> *list_;
};

// the pointer part of every list is the same
// lists differ by data part
template <typename T>
class node
{
public:
  node() : next_(nullptr) {}
  node(const T item) : data_(item), next_(nullptr) {}
  // functions can be inlined
  T getData() const { return data_; }
  void setData(const T &data) { data_ = data; }

  // or can be defined outside
  node<T> *getNext() const;
  void setNext(node<T> *const);

private:
  T data_;
  node<T> *next_;
};

//
// member functions for node
//
template <typename T>
node<T> *node<T>::getNext() const
{
  return next_;
}
//going off of hwer i am not hwere ill be
template <typename T>
void node<T>::setNext(node<T> *const next)
{
  next_ = next;
}

template <typename T>
void Collection<T>::add(const T &item)
{
  node<T> *temp = new node<T>;
  temp->setData(item);
  temp->setNext(list_);
  list_ = temp;
}

template <typename T>
void Collection<T>::remove(const T &item)
{
  if ( list_ == nullptr) return;
  if (list_->getData() == item){
    node<T> *temp = list_;
    temp = temp->getNext();
    delete list_;
    list_ = temp;
  }
  //cout<<"here"<<endl;
  node<T> *current = list_;
  node<T> *oneBefore = list_;
  while (current != nullptr){
    if(current->getData() == item){
      //cout << current->getData();
      node<T> * temp = current;
      current = current->getNext();
      delete temp;
      oneBefore->setNext(current);
    }
    if (current != list_){
      oneBefore = oneBefore->getNext();
    }
    current = current->getNext();
  }
}
template <typename T>
T Collection<T>::last() const {
  return list_->getData();
};
template <typename T>
void Collection<T>::print(){
  node<T>* ptr = list_;
  //node<T> *const tmp = ptr;
  while (ptr != 0){
    cout<< ptr->getData();
    ptr = ptr->getNext();
  }
  cout << endl;
};

template <typename T>
bool equal(const Collection<T> & one, const Collection<T> & two)
{
  node<T>* ptr1 = one.list_;
  node<T>* ptr2 = two.list_;
  //cout<<"iin equal"<<endl;
  while (ptr1 != 0 || ptr2 != 0){
    if( ptr1->getData() != ptr2->getData())
    return false;
    ptr1 = ptr1->getNext();
    ptr2 = ptr2->getNext();
  }
  return true;
}

// //template <typename T>
// Collection<T>::~Collection()
// {
//   node<T> *temp = 0;
//   while (list_ != 0)
//   {
//     temp = list_;
//     list_ = list_->getNext();
//     delete temp;
//   }
// }

template <typename T>
Collection<T>::Collection(const Collection<T> &actual) : Collection<T>()
{ // copy constructor
  node<T> *temp = actual.list_;
  node<T> *bottom;
  while (temp != 0)
  {
    if (list_ == 0)
    {
      list_ = temp;
      bottom = list_;
    }
    else
    {
      bottom->setNext(temp);
      bottom = bottom->getNext();
    }
    temp = temp->getNext();
  }
}

template <typename T>
void Collection<T>::swap(Collection<T> &rhs)
{
  node<T> *temp = list_;
  list_ = rhs.list_;
  rhs.list_ = temp;
}

#endif // LIST_HPP_

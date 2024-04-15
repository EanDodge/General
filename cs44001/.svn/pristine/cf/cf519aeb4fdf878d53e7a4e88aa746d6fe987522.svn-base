//Ean Dodge
//using Dr nesterenko code
// 2/2/2024

#include <iostream>
#include "list.hpp" // list template

using std::cout; using std::endl;

int main(){
   node<int> *head, *currentPtr;

   // 
   // integer list manipulation
   // 

   // first node
   head =new node<int>;
   head->setData(1);


   currentPtr=new node<int>;  // second node
   currentPtr->setData(2);

   head->setNext(currentPtr); // list contains two nodes

   cout << head->getData() << " "; // printing head node

   // deallocating head node
   currentPtr=head;
   head=head->getNext();
   delete currentPtr;

   // printing and deallocating the last element
   cout << head->getData() << endl;
   delete head;


   // 
   // character list manipulation
   // 
   
   // allocating head node
   node<char> *charHead = new node<char>;
   node<char> *current = charHead;
   current->setData('A');

   // creating list
   for(char letter = 'B'; letter <= 'Z'; ++letter){
      node<char> *const newNode = new node<char>;
      newNode->setData(letter);
      current->setNext(newNode);
      current = newNode;
   }


   for(current = charHead;  current != nullptr; current=current->getNext())
     cout << current->getData() << ' ';
   cout << endl;


   Collection<int> mine;

   mine.add(5);
   for(int i = 0; i < 10; ++i){
      mine.add(i);
   }
   mine.print();
   mine.remove(5);
   //cout<<"here"<<endl;
   mine.print();
   mine.last();

}


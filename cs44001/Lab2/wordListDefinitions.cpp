//Ean Dodge
//source file for definitions

#include "WordList.hpp"

WordList::WordList(const WordList& actual){
    //copy constructor
    size_ = actual.size_;
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i<size_; ++i)
        wordArray_[i] = actual.wordArray_[i];
}

void WordList::swap(WordList& rhs){
    //for operator=
    WordOccurrence *tmp = wordArray_;
    wordArray_ = rhs.wordArray_;
    rhs.wordArray_ = tmp;

    int temp = size_;
    size_ = rhs.size_;
    rhs.size_ = temp;
}
WordList& WordList::operator=(WordList rhs){
    swap(rhs);
    return *this;
}

void WordOccurrence::swap(WordOccurrence& rhs){
    //for operator=
    string tmp = word_;
    word_ = rhs.word_;
    rhs.word_ = tmp;

    int temp = num_;
    num_ = rhs.num_;
    rhs.num_ = temp;
}

WordOccurrence& WordOccurrence::operator=(WordOccurrence rhs){
    swap(rhs);
    return *this;
}

void WordList::addWord(const string& str){
    //make a new WordOCC with the string given
    //and with only one of them
    WordOccurrence newStr(str,1);
    //increment size by ine in the word array
    int newSize = size_ + 1;
    //make a new wordlist with new svize and make a new array
    WordList tmp(newSize);    
    //go through and set every element of tmp 
    //to the actual word array
    for(int i= 0; i < size_; ++i)
        tmp.wordArray_[i] = wordArray_[i];
    
    //make last element new word OCC
    tmp.wordArray_[size_] = newStr;
    //cout << tmp.wordArray_[size_].getNum() <<endl;
    //delete the actual word array and make it tmp
    size_ = newSize;
    delete [] wordArray_;
    wordArray_ = new WordOccurrence[size_];
    for(int i= 0; i < size_; ++i){
        wordArray_[i] = tmp.wordArray_[i];

    }
    
}
bool equal(const WordList& one, const WordList& two){
    if (one.size_!= two.size_){  //checks first to see if the size is off
        return false;
    }
    //will go through the word array word by word
    for(int i = 0; i < one.size_; i++){ 
        //uses predicate function matchword
        //to compare and get word to get a string
        if(!(one.wordArray_[i].matchWord(two.wordArray_[i].getWord())))
        //will return false if they do not equal
            return false;                
            
    }
    //if all do not return false, will return true
    return true;
}

int WordList::check(const string& str)const{
    //go through and see if the str is in the array
    for(int i = 0; i < size_; ++i){
        if (wordArray_[i].getWord() == str)
            return i;
    }
    return -1;
}

void WordList::print(){
    // go through the array and print the word and the number of occurrences
    for(int i =0; i < size_; ++i){
        cout<<wordArray_[i].getWord() << " " << wordArray_[i].getNum() <<endl;
    }
}
// //insertion sort
// void WordList::mySort()
// {
//     int key, j;
//     for (int i = 1; i < size_; i++) {
//         key = wordArray_[i].getNum();
//         j = i - 1;
        
//         // Move elements of arr[0..i-1],
//         // that are greater than key, to one
//         // position ahead of their
//         // current position
//         while (j >= 0 && wordArray_[j].getNum() > key) {
//             wordArray_[j + 1] = wordArray_[j];
//             j = j - 1;
//         }
//         wordArray_[j + 1] = wordArray_[i];
//     }
// }
//this was my sort(not too good)
void WordList::mySort(){
    //no change is a bool to get out of th while loop if we are done
    bool nochange = false;
    while (!nochange){
        bool flag = true;
        for(int i = 1; i < size_; ++i){
            //if 1 < 2, then switch them
            if(wordArray_[i].getNum()< wordArray_[i-1].getNum()){
                WordOccurrence tmp = wordArray_[i];
                wordArray_[i] = wordArray_[i-1];
                wordArray_[i-1] = tmp;
                //we changed it, so flag = false
                flag = false;
            }
        }
        //if we didnt change, then be done
        if (flag) nochange = true;
    }
}
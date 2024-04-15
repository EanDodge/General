//Ean Dodge
//header file based off of Dr. Nesterenko's header

#ifndef WordListM
#define WordListM

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

class WordOccurrence {
public:
    //constructor
    WordOccurrence(const string& word = "", const int num = 0): word_(word), num_ (num) {};
    bool matchWord(const string &str){return (word_ == str);}; // returns true if word matches stored
    void increment() {++num_;}; // increments number of occurrences
    string getWord() const {return word_;}; //accessor
    int getNum() const {return num_;}; //accessor
    WordOccurrence& operator=(WordOccurrence); //assignment operator
    void swap(WordOccurrence&); //for assignment operator
    


private:
    string word_;
    int num_;
};

class WordList{
public:
    //constructor
    WordList(int num = 0) {size_ = num; wordArray_ = new WordOccurrence[size_];};
    ~WordList() {delete [] wordArray_;};//destructor
    WordList(const WordList&); //copy constructor
    WordList& operator=(WordList); //assignment operator
    void swap (WordList&); //V2 of assignment operator

    void mySort(); //sort

    void increment(int i){wordArray_[i].increment();}; //increment word occurrence

    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    int check(const string&) const; //check to see if the str is int the array

    void addWord(const string &); //add word to the array
    void print();

    // Only use for testing purposes
    WordOccurrence * getWords() const {return wordArray_;};
    int getSize() const {return size_;};
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

#endif
#include "string.hpp"
#include <cassert>


String::String()
{
    stringSize = 1;
    str= new char[stringSize];
    str[0] = '\0';
}

String::String(char ch)
{
    if(ch != '\0'){
        stringSize = 2;
        str = new char[stringSize];
        str[0] = ch;
        str[1] = '\0';
    }
    else{
        stringSize = 1;
        str= new char[stringSize];
        str[0] = '\0';
    }
}

String::String(const char s[])
{
    stringSize = 0;
    while (s[stringSize] != 0)
    {
        ++stringSize;
    }
    str = new char[++stringSize];
    for(int i = 0; i < stringSize; ++i){
        str[i] = s[i];
    }
    str[stringSize] = '\0';

}
int String::capacity() const
{
    return stringSize-1;
}
int String::length() const
{
    return stringSize-1;
}

// Requires: 0 <= i < length()
char String::operator[](int i) const
{
    // want to do cout<<b[0]
    assert(i >= 0);
    assert(i < length()); // calls it on "this"//a keyword that is a pointer to the object the method was called upon
    return str[i];
}
// char & you return a pointer to where you return too
char &String::operator[](int i)
{ // you can modify this since there is no const
    // want to do b[0] = 'x'
    assert(i >= 0);
    assert(i < length());
    return str[i];
}

String &String::operator+=(const String &rhs){
    int offset = length();
    int rhsLen = rhs.length();
    String tmp;
    tmp.stringSize = offset + rhsLen + 1;
    for(int i = 0; i<offset; ++i)
        tmp = str;
    int i = 0;
    while (i < rhsLen)
    {
        if (offset + i >= capacity() + rhs.capacity())
            break;
        tmp.str[offset + i] = rhs.str[i];
        ++i;
    }
    tmp.str[offset + i] = 0;
    *this = tmp;
    return *this;
    }



String operator+(String lhs, const String &rhs)
{
    return (lhs) += (rhs);
}

bool String::operator==(const String &rhs) const
{
    int i = 0;
    while (str[i] != 0 && (rhs.str[i] != 0) &&
            (str[i] == rhs.str[i]))
        ++i;
    return str[i] == rhs.str[i]; // loops till difference, if different, this case will be false, if true, this has to be true
}

bool operator==(char lhs, const String &rhs)
{
    return String(lhs) == rhs;
}
bool operator==(const char lhs[], const String &rhs)
{
    return String(lhs) == rhs;
}

bool String::operator<(const String &rhs) const
{
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))
    {
        ++i;
    }
    return str[i] < rhs.str[i];
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}
bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs)
{
    return !(lhs > rhs);
}
bool operator<(char lhs, const String &rhs)
{
    return String(lhs) < rhs;
}
bool operator<(const char lhs[], const String &rhs)
{
    return String(lhs) < rhs;
}
bool operator>=(const String &lhs, const String &rhs)
{
    return !(rhs < lhs);
}

// REQUIERS: 0 <= start <= end < length()
// ENSURES: retVal == str[start,...,end]
String String::substr(int start, int end) const
{
    String result;;
    result.str = new char[stringSize];
    if (start < 0)
        start = 0;
    if (end < start)
        return String();
    if (end >= length())
        end = length() - 1;

    for (int i = start; i <= end; ++i)
    {
        result += str[i];
    }
    return result;
}

// Requiers: 0 <= start < length()'
// Ensures: retVal == i : str[i] == ch; || -1 if no ch in str
int String::findch(int start, char ch) const
{
    if (start < 0)
        start = 0;
    if (start >= length())
        return -1;
    int i = start;
    while ((str[i] != 0) && (str[i] != ch))
        ++i;
    if (str[i] == ch)
        return i;
    else
        return -1;
}

int String::findstr(int start, const String &array) const
{
    if (start < 0)
        start = 0;
    if (start >= length())
        return -1;
    int size = array.length(), i = 0;
    String result = substr(i, (size + i) - 1);
    while (!(result == array) && (length() - i != size))
    {
        ++i;
        result = substr(i, (size + i) - 1);
    }
    if (result == array)
        return i;
    else
        return -1;
}

std::istream& operator>>(std::istream& in , String& rhs){
    char ch [rhs.stringSize];
    in >> ch;
    String temp(ch), space(" ");
    rhs += temp;
    rhs += space;
    
    return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs){
    int i = 0;
    while(i < rhs.length()){
        out<<rhs[i];
        ++i;
    }
    return out;
}

String::~String(){
    delete [] str;
}

String::String (const String& rhs){ //copy constructor
    stringSize = rhs.stringSize;
    str = new char[stringSize];
    for(int i = 0; i < stringSize; ++i)
    {
        str[i] = rhs.str[i];
    }
}

void String::swap(String& rhs){
    char *temp = str;
    str = rhs.str;
    rhs.str = temp;
    int ctmp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = ctmp;
}

String& String::operator=(String rhs){
    swap(rhs);
    return *this;
}                   


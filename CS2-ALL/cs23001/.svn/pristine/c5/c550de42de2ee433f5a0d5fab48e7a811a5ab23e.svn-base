#ifndef UTILITIES
#define UTILITIES

#include<iostream>
#include "../string/string.hpp"
#include "stack.hpp"

String infix_to_postfix           (std::ostream& out, std::istream& in, bool);
void   printInfix                 (std::ostream& out, std::istream& in);
String postfix_to_assembly(String, std::ostream& out);
bool   isOperator   (const String&);
String evaluate     (const String&, const String&, const String&, std::ostream&, int& );
String oper         (const String&);
String num2string                                                               (int);
#endif 
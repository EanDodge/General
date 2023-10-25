#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"
#include <vector>
#include <fstream>
#include "utilities.hpp"

String infix_to_postfix(std::ostream &out, std::istream &in, bool first) 
{
    stack<String> S;
    String op, lhs, rhs;
    String token;
    in >> token;
    if (!first)//the first one does not have ( taken away, so we dont want to add a second one
        out << "( ";
    out << token << " "; //print out infix
    // if(token == "") return String();
    while (token != ';')
    {
        // std::cout<<"in while"<<std::endl;
        if (token == ')')
        {
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            // std::cout<<op<<lhs<<rhs<<std::endl;
            S.push(lhs + " " + rhs + " " + op); //postfix formation
        }
        else if (token != '(')
        {
            String temp = " ";
            temp = token;
            S.push(temp);
        }
        in >> token; 
        if (token != ";")
            out << token << " "; // print infix
    }
    in >> token;//input to check for endline, will add ( for printing purpose
    // out<<'\n'<<"( ";
    if (token == "" || token == "\n" || token == "\r")
        return String();
    return S.pop();//return top of stack
}

bool isOperator(const String &oper)
{
    if (oper == "+" || oper == "-" ||
        oper == "*" || oper == "/")
        return true; //return if it is an operator
    return false;
}

String oper(const String &op) // will return instruction from instruction set
{
    assert(isOperator(op));
    if (op == "+")
        return "AD";
    if (op == "-")
        return "SB";
    if (op == "*")
        return "MU";
    if (op == "/")
        return "DV";
    return String();
}
String num2String(int n)//turn number to string
{
    int singles = n % 10;
    int tens = n / 10;
    if (tens > 0)//if there are at least 10
    {
        char tentmp = tens + int('0');
        char singtmp = singles + int('0'); // turn it to charcter
        String tenstr(tentmp);
        String singstr(singtmp);//then to string 
        tenstr += singstr;//put them together and return it
        return tenstr;
    }
    else //less than 10
    {
        char singtmp = singles + int('0');
        String singstr(singtmp);
        return singstr;
    }
}
String evaluate(const String &left, const String &T, const String &right, std::ostream &out, int &n)
{
    String tmp("TMP");
    tmp += num2String(n);//tmp(number)
    out << "   "
        << "LD"                                 //format  LD(left) - instruction(right) - ST tmp(number)
        << "     " << left << '\n';
    out << "   " << oper(T) << "     " << right << '\n';
    out << "   "
        << "ST"
        << "     " << tmp << '\n';
    ++n;
    return tmp;
}

String postfix_to_assembly(String post, std::ostream &out)
{
    // std::cout<<"in func"<<std::endl;
    if (post.length() == 0)
        return String();
    // std::cout<<post.length();
    std::vector<String> expr;
    stack<String> S;
    String left, right, T;
    expr = post.split(' '); // splits by space
    int n = 1;
    size_t i = 0;
    while (i < expr.size())
    {
        // std::cout<<"in while"<<std::endl;
        T = expr[i];
        if (!isOperator(T))
            S.push(T); //push if not operator
        else
        {
            // std::cout<<"else"<<std::endl;
            right = S.pop();
            left = S.pop();
            S.push(evaluate(left, T, right, out, n));
        }
        ++i;
    }
    return S.pop();
}

void printInfix(std::ostream &out, std::istream &in)
{
    String output;
    out << "Infix expression: ";
    output = infix_to_postfix(out, in, true); // true because it is the first(will not print extra (  
    while (!in.eof())
    {
        out << '\n'
            << "Postfix expression: ";
        out << output << '\n';
        postfix_to_assembly(output, out);
        std::cout << "\n";
        out << "Infix expression: ";
        output = infix_to_postfix(out, in, false);
    }
    out << '\n'
        << "Postfix expression: ";
    out << output << '\n';
    postfix_to_assembly(output, out);//last one
}

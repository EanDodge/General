#include<iostream>
#include<cassert>
#include"string.hpp"
int main(){
    {
        String one("How");
        String two("dy");
        String result;
        result = one + two;
        assert(result == "Howdy");

    }
    {
        String one;
        String two("dy");
        String result;
        result = one + two;
        assert(result == "dy");
    }
    
    {
        String one("How");
        String two;
        String result;
        result = one + two;
        assert(result == "How");
    }
    {
        String one("Howdy Partner, how was your day? Cause mine was awesome");
        String two(" it was good...");
        String result;
        result = one + two;
        assert(result == "Howdy Partner, how was your day? Cause mine was awesome it was good...");
    }
    {
        String one("kbwdciurgkniyveihxfqkfjwnfiwy s;lxnweiocerojkc eihcvwekjcbwiycvwdkjccbdihcvdwkjc wdihcvwdckjwd cihwdvc kwdlc dwi");
        String two("dy");
        String result;
        result = one + two;
        assert(result == "kbwdciurgkniyveihxfqkfjwnfiwy s;lxnweiocerojkc eihcvwekjcbwiycvwdkjccbdihcvdwkjc wdihcvwdckjwd cihwdvc kwdlc dwidy");
    }
    {
        String one("h2xK5vjY1Lx87B2I2lCIH2ZpqqwMfM6tD39q94CUvcEOnOjJnwx2WTo3t2SDpye1TjyJXwI8yOvOgBPISkHRhyyyt2pl7WNJC6OnOnlEtYgWJiLnf8K6tLexNA5eiXJeJ1mOS6qwDI54x2FZ2IgitFwCpRRFvgRTBSUxcG38wVs2uuwj5gxQoWJZCYW9Z7Rcd0UsbNn82YFCqqE4A");
        String two("d");
        String result;
        result = one + two;
        assert(result == "h2xK5vjY1Lx87B2I2lCIH2ZpqqwMfM6tD39q94CUvcEOnOjJnwx2WTo3t2SDpye1TjyJXwI8yOvOgBPISkHRhyyyt2pl7WNJC6OnOnlEtYgWJiLnf8K6tLexNA5eiXJeJ1mOS6qwDI54x2FZ2IgitFwCpRRFvgRTBSUxcG38wVs2uuwj5gxQoWJZCYW9Z7Rcd0UsbNn82YFCqqE4Ad");
    }
    {
        String one;
        String two;
        String result;
        result = one + two;
        assert(result == "");
    }
    {
        String one("ab");
        String two("ab");
        one += two;
        assert(one == "abab");
    }
   {
        
            String one("hello ");
            assert(one == "hello ");
            String two("world");
            assert(two == "world");
            one += two;
            assert(one == "hello world");
        
    }
    }


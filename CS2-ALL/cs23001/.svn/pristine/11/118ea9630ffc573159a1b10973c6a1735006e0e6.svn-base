#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
    {
        String one("Hello");
        assert(one == "Hello");
    }
    {
        char two[6] = "Hello";
        String one(two);
        assert(one == two);
    }
    {
        String one(" ");
        assert(one == " ");
    
    }
    {
        char two[2] = " ";
        String one(two);
        assert(one == two);
    }
    {
        char two[100] = "Lu9dNi8kXhXgA8QY0CcWfKGFfkQLFBXDjv2wPpi10a57dOXoN6yZvOjE9ge9DLeIlrNidTvRwzV7FMSPRv0R7PQslLgwUxXIMJ4";
        String one(two);
        assert(one == "Lu9dNi8kXhXgA8QY0CcWfKGFfkQLFBXDjv2wPpi10a57dOXoN6yZvOjE9ge9DLeIlrNidTvRwzV7FMSPRv0R7PQslLgwUxXIMJ4");
        assert(one == two);
    }
    {
        String one("I love computer science so much, this is my fav");
        assert( one == "I love computer science so much, this is my fav");
    }
}

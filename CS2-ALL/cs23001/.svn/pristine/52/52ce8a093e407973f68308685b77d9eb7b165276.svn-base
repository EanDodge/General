#include <iostream>

//========================================================================
int fib(int);
int fibTail(int);

//========================================================================
int main()
{
    // Prompt, get input
    std::cout << "\nFibonacci, enter a nonnegative integer: ";
    int non_neg_int;
    std::cin >> non_neg_int;

    for(int i = 0; i <= non_neg_int; ++i){
        std::cout<<fib(i)<< " ";
    }
    std::cout<<std::endl;
    // Compute fibonacci
    int fibonacci = fib(non_neg_int);
    

    // Output result
    std::cout << "The fibonacci of "
              << non_neg_int
              << " is "
              << fibonacci
              << ".\n\n";

    return 0;
}

//========================================================================
//   Nonnegative int argument required.
//   Compute and return the fibonacci of the argument,
//
int fib(int num)
{
    if (num == 1 || num == 0)
        // Base case, by definition
        return 1;
    else
    {
        // Recursive case;
        int fib_minus_1 = fib(num - 1);
        int fib_minus_2 = fib(num - 2);
        //std::cout << fib_minus_1 << " + " << fib_minus_2<<std::endl;
        return fib_minus_1 + fib_minus_2;
    }
}

int fibTail(int num){
    if (num == 1 || num == 0)
        // Base case, by definition
        return 1;
    else
    {
        // Recursive case;
        
        return fibTail(num -1) + fibTail(num -2);
    }
}


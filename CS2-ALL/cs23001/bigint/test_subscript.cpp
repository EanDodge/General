// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main()
{

    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi == 4); // Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }

    {
        bigint bi(0);
        bigint be(220);
        bigint bo;

        bi.debugPrint(std::cout);
        be.debugPrint(std::cout);

        bo = bi + be;
        bo.debugPrint(std::cout);
        std::cout<<bo[1];
        std::cout<<std::endl;
        assert(bo[1]==2);
    }
    {
        bigint bi("1234567890");
        bigint be("345");
        assert(bi[1] == 9);

    }
    {
        bigint bi;
        bi[0]= 1;
        assert(bi == 1);
        std::cout<<bi;
    }
    {
        bigint bi;
        bi[260]= 5;
        std::cout<<bi;
    }
    {
        bigint bi;
        bi[5] = 5;
        assert(bi[5]==5);
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}
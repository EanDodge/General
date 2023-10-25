// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

        // Verify
        //assert(bi == 77);  //Wrong. Will FAIL, fix and add tests cases
        assert(bi == 3);
        bi = bi.times10(1);
        assert(bi == 30);
    }
    {
        bigint bi(1234567890);
        assert(bi == 1234567890);
        bi = bi.times10(5);
        assert(bi == "123456789000000");
    }
    {
        bigint bi;
        
        bi = bi.times10(500);
        assert(bi == 0);
    }
    {
        bigint bi(1);

        bi = bi.times10(CAPACITY - 1);
        std::cout<<bi;
        
    }
    {
        bigint bi(1);
        bi = bi.times10(CAPACITY - 1);
        bi = bi.timesDigit(0);
        assert(bi == 0);
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi(89087564);
        bi = bi.times10(160);

        std::cout<<bi<<std::endl;
    }
    {
        bigint bi("2");
        for(int i = 0; i < CAPACITY-1; ++i)
            bi = bi.times10(1);
        std::cout<<bi<<std::endl;
    }

    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}


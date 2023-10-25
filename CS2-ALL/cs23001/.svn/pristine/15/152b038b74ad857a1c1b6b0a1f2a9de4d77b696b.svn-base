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
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  
    }
    {
        bigint bi("12345678901234567890");
        assert(bi == "12345678901234567890");
        bi = bi.timesDigit(3);
        assert(bi == "37037036703703703670");
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi;
        bi = bi.timesDigit(500);
        assert(bi == 0);
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi(500);
        bi = bi.timesDigit(0);
        assert(bi== 0);
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi(1111111);
        bigint bo(9);
        bi = bi.timesDigit(bo[0]);
        assert(bi == 9999999);
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi("123456789");
        bi = bi.timesDigit(9);
        assert(bi == "1111111101");
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi(2);
        for(int i = 1; i < 10; ++i){
            bi = bi.timesDigit(i);
        }
        std::cout<<bi<<std::endl;
    }
    {
        bigint bi(500);
        for(int i = 1; i < 10; ++i){
            bi = bi.timesDigit(i);
        }
        std::cout<<bi<<std::endl;
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}

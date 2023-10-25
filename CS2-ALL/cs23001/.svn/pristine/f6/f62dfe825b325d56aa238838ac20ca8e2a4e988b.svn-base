#include"string.hpp"
#include<iostream>
#include<cassert>


int main(){
    {
        String A;
        String B;
        A = B;
        assert(A == B);
        assert(A == "");
    }
    {
        String A("helooj2ocjbrir3ridbeijxbeiyxveihd 3ercfveix eixveiyxve2iuxve2iycxveiucg3riygf3rofg3r089hgfowerufgeq;kdcbnqeoudv   qwkldbqeiudvqelkfb  wudvl   wkbceiycxw  K");
        String B;
        A = B;
        assert(A == B);
        assert(A == "");
    }
    {
        String A;
        String B("helooj2ocjbrir3ridbeijxbeiyxveihd 3ercfveix eixveiyxve2iuxve2iycxveiucg3riygf3rofg3r089hgfowerufgeq;kdcbnqeoudv   qwkldbqeiudvqelkfb  wudvl   wkbceiycxw  K");
        A = B;
        assert(A == B);
        assert(A == "helooj2ocjbrir3ridbeijxbeiyxveihd 3ercfveix eixveiyxve2iuxve2iycxveiucg3riygf3rofg3r089hgfowerufgeq;kdcbnqeoudv   qwkldbqeiudvqelkfb  wudvl   wkbceiycxw  K");
    }
    {
        String A("hello");
        A = A;
        assert(A == "hello");
    }
    {
        String A("hello");
        String B;
        String C(" world");
        B = C;
        A += B;
        assert(B == C);
        assert(A == "hello world");
    }
    {
        String A("hekwcciehcb3riug3roufb3ricb3riugr3iucb roucbvr9iurcvrojcbjcb3eiycv3rircb3riycvihcb3ihcvwkihcbqsxjfweidcbewojcvwdkxhvqewljxbrwiycvtivh4ryvciercbeocjgedocjbwcojwvcro");
        String B("wdkcv2iecv2pifbv3r8fg3875t5iyt548yfh3pfbw3ioufv3rofbn3rorifhweocmwepdcmedlxnqslcbwdocb3wr9ufv3rwoucb3rydcv3rofkn'wemlfe;knfcejrfbvc3irofv3roufb3roibf3eru9cgrwocjbweojfvweiycvweoicwbicwgdcubvwcojrwbcourcvwrjkfc wrofcr9ucbri");
        B = A;
        assert(B==A);
        assert(B == "hekwcciehcb3riug3roufb3ricb3riugr3iucb roucbvr9iurcvrojcbjcb3eiycv3rircb3riycvihcb3ihcvwkihcbqsxjfweidcbewojcvwdkxhvqewljxbrwiycvtivh4ryvciercbeocjgedocjbwcojwvcro");
    }
}

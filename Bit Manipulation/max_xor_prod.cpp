//https://leetcode.com/problems/maximum-xor-product/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int mod = (1e9+7);
    int maximumXorProduct(long long a, long long b, int n) {
        ll xXora=0;
        ll xXorb=0;
        //the bits before nth bit remain unchanged
        //therefore same as a and b 
        for(ll i=49; i>=n; i--){
            int a_ith_bit = ((a>>i)&1);
            int b_ith_bit = ((b>>i)&1);

            if(a_ith_bit==1){
                xXora = xXora^(1ll<<i);
            }
            if(b_ith_bit==1){
                xXorb = xXorb^(1ll<<i);
            }
        }

        //from (n-1)th bit to 0th bit
        for(ll i=n-1; i>=0; i--){
            int a_ith_bit = ((a>>i)&1);
            int b_ith_bit = ((b>>i)&1);

            //if the ith bits are same in a and b
            //we can get a 1 in the xored result for both
            if(a_ith_bit == b_ith_bit){
                xXora = xXora^(1ll<<i);
                xXorb = xXorb^(1ll<<i);
                continue;
            }

            //if the ith bit is diff, give the 1 to the smaller one
            if(xXora<xXorb){
                xXora = xXora^(1ll<<i);
            }else{
                xXorb = xXorb^(1ll<<i);
            }
        }

        xXora = xXora%mod;
        xXorb = xXorb%mod;

        return (xXora*xXorb)%mod;
    }
};
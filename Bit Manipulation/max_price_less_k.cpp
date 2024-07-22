//https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    typedef long long ll;
    vector<ll>bitCount;
public:
    void getBitCount(ll num){
        if(num==0){
            return;
        }
        
        if(num==1){
            bitCount[0] += 1;
            return;
        }
        
        if(num==2){
            bitCount[0] += 1;
            bitCount[1] += 1;
            return;
        }

        ll bitLen = log2(num)+1;
        ll temp = bitLen-1;
        ll nearPower2 = pow(2,temp);

        bitCount[bitLen-1] += num-nearPower2+1;

        for(ll i=0; i<bitLen-1; i++){
            bitCount[i] += nearPower2/2;
        }

        num = num - nearPower2;
        getBitCount(num);

    }
    long long findMaximumNumber(long long k, int x) {
        ll s = 0;
        ll e = 1e15;
        ll result =0;
        
        while(s<=e){
            ll mid = s+(e-s)/2;
            bitCount = vector<ll>(65,0);
            getBitCount(mid);

            ll totalPrice=0;
            for(ll i=0; i<log2(mid)+1; i++){
                if((i+1)%x==0){
                    totalPrice += bitCount[i];
                }
            }

            if(totalPrice<=k){
                result = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }

        }

        return result;
    }
};
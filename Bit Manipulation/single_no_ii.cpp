//https://leetcode.com/problems/single-number-ii/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0; k<32; k++){
            int cntOne=0, cntZero=0;
            int temp = 1<<k;
            for(int num:nums){
                if((num&temp)==0){
                    cntZero++;
                }else{
                    cntOne++;
                }
            }
            //if number of 0s are a multiple of 3, kth bit of the result is 1
            if(cntZero%3==0){
                result = result|temp;
            }
        }
        return result;
    }
};
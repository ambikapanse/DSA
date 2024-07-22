//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            res = res^nums[i];
        }

        return __builtin_popcount(res^k);
    }
};
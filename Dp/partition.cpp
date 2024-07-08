//https://leetcode.com/problems/partition-equal-subset-sum/
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<2)
        return false;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If totalSum is odd, it's not possible to partition it into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int sum = totalSum / 2;
        vector<vector<bool>>dp(nums.size(), vector<bool>(sum+1,0));
        
        //when sum==0 then sum is reached, hence for that index -> true
        for(int i=0; i<nums.size(); i++){
            dp[i][0] = true;
        }
        
        /// For the first element, the sum is reached only if it's equal to the element itself
        if (nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }
        
        for(int i=1; i<nums.size(); i++){
            for(int target=1; target<=sum; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(nums[i]<=target){
                    take = dp[i-1][target-nums[i]];
                }
                dp[i][target]=take|notTake;
            }
        }
        
        return dp[nums.size()-1][sum];
    }
};
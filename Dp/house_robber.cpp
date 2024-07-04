#include<iostream>
#include<vector>
using namespace std;

//memoization
class Solution {
public:
    int robber(int index, vector<int>& nums, vector<int>& dp){
        //base case
        if(index==0){
            return nums[0];
        }
        if(index<0) return 0;

        //check if in dp
        if(dp[index]!=-1) return dp[index];

        //not in dp, then put in dp
        //include house
        int incl = nums[index] + robber(index-2, nums, dp);
        //excluse house
        int excl = 0 + robber(index-1, nums, dp);

        return dp[index]= max(incl,excl);

    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int result = robber(nums.size()-1, nums, dp);
        return result;
    }
};

//tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1);
        dp[0] = nums[0];
        for(int i=1; i<nums.size();i++){
            int incl = nums[i];
            if(i>1)
            incl = nums[i] + dp[i-2];
            int excl = 0 + dp[i-1];
            dp[i] = max(incl, excl);
        }

        return dp[nums.size()-1];
    }
};
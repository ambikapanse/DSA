//https://leetcode.com/problems/house-robber-ii/
#include<iostream>
#include<vector>
using namespace std;

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
        vector<int>temp1, temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums.at(i));
            if(i!=nums.size()-1) temp2.push_back(nums.at(i));
        }
        int res1 = robber(temp1.size()-1, temp1, dp);
        vector<int>dp2(nums.size()+1,-1);
        int res2 = robber(temp2.size()-1, temp2, dp2);
        return max(res1,res2);
    }
};
//This code ONLY works for POSITIVE INTEGERS IN ARRAY
//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        
        //when sum==0 then sum is reached, hence for that index -> true
        for(int i=0; i<nums.size(); i++){
            dp[i][0] = true;
        }
        
        // Base case: for a single element, the sum is reached when sum==itself
        if (nums[0] <= sum && nums[0] >= 0) {
            dp[0][nums[0]] = true;
        }

        //dp[i][j] signifies if the array until i can produce a sum j -> true/false
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
        
        int mini = 1e9;
        for(int i=0; i<=sum/2; i++){
            if(dp[nums.size()-1][i]==true){
                int s1 = i;
                int s2 = sum-i;
                mini = min(mini, abs(s2-s1));
            }
        }
        
        return mini;
    }
};
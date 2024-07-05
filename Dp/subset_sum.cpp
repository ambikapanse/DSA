//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include<iostream>
#include<vector>
using namespace std;

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<bool>>dp(arr.size(), vector<bool>(sum+1,0));
        
        //when sum==0 then sum is reached, hence for that index -> true
        for(int i=0; i<arr.size(); i++){
            dp[i][0] = true;
        }
        
        //for a single element, the sum is reached when sum==itself
        dp[0][arr[0]] = true;
        
        for(int i=1; i<arr.size(); i++){
            for(int target=1; target<=sum; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(arr[i]<=target){
                    take = dp[i-1][target-arr[i]];
                }
                dp[i][target]=take|notTake;
            }
        }
        
        return dp[arr.size()-1][sum];
        
    }
};
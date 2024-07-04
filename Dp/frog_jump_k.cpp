//https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        
        vector<int>dp(n);
        dp[0] = 0;
        
        for(int i=1;i<n;i++){
            int minSteps = INT_MAX;
            for(int j=1;j<=k;j++){
                //check if i-j index exists
                if(i-j>=0){
                    int jumps = dp[i-j] + abs(height[i]-height[i-j]);
                    minSteps = min(minSteps, jumps);
                }else{
                    break;
                }
            }
            dp[i] = minSteps;
        }
        
        return dp[n-1];
    }
};
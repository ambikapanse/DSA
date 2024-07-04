//https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int left = dp[i-1]+abs(height[i]-height[i-1]);
            int right = INT_MAX;
            if(i>1)
            right = dp[i-2]+abs(height[i]-height[i-2]);
            dp[i] = min(left,right);
        }
        
        return dp[n-1];
    }
};
//https://leetcode.com/problems/fibonacci-number/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int fib(int n) {
        vector<int>dp(n+1);
        dp[0] = 0;
        if(n!=0)
        dp[1] = 1;
        for(int i=2; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
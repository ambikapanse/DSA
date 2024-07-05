//https://leetcode.com/problems/triangle/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //recursion
    int rec(vector<vector<int>>& triangle, int i, int j){
        //base case
        if(i==triangle.size()-1){
            return triangle[i][j];
        }

        int down = rec(triangle, i+1, j) + triangle[i][j];
        int diagonal = rec(triangle, i+1, j+1) + triangle[i][j];

        return min(down,diagonal);
    }

    //tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n));
        for(int j=n-1;j>=0;j--){
            dp[m-1][j] = triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i; j>=0; j--){
                int down = dp[i+1][j]+triangle[i][j];
                int diagonal = dp[i+1][j+1]+triangle[i][j];
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};
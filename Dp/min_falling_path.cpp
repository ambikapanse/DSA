//https://leetcode.com/problems/minimum-falling-path-sum/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//recursion
int rec(vector<vector<int>>& matrix, int i, int j){
        //base case
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        int ldiagonal=1e9, rdiagonal=1e9;
        int down = rec(matrix, i+1, j) + matrix[i][j];
        if(j-1>=0) ldiagonal = rec(matrix, i+1, j-1) + matrix[i][j];
        if(j+1<matrix.size()) rdiagonal = rec(matrix, i+1, j+1) + matrix[i][j];

        return min(rdiagonal, min(down, ldiagonal));
    }

int minFallingPathSum(vector<vector<int>>& matrix) {
    int result = INT_MAX;
    for(int j=0;j<matrix.size();j++){
        result = min(result, rec(matrix, 0, j));
    }
    return result;
}

//tabulation
class Solution {
public:
    int rec(vector<vector<int>>& matrix, int i, int j){
        //base case
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        int ldiagonal=1e9, rdiagonal=1e9;
        int down = rec(matrix, i+1, j) + matrix[i][j];
        if(j-1>=0) ldiagonal = rec(matrix, i+1, j-1) + matrix[i][j];
        if(j+1<matrix.size()) rdiagonal = rec(matrix, i+1, j+1) + matrix[i][j];

        return min(rdiagonal, min(down, ldiagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));

        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int ldiagonal = 1e9, rdiagonal = 1e9;
                int down = dp[i-1][j] + matrix[i][j];
                if(j-1>=0) ldiagonal = dp[i-1][j-1] + matrix[i][j];
                if(j+1<n) rdiagonal = dp[i-1][j+1] + matrix[i][j];
                dp[i][j] = min(rdiagonal, min(down, ldiagonal));
            }
        }
        int minPathSum = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            minPathSum = min(minPathSum, dp[n - 1][j]);
        }

        return minPathSum;
    }
};
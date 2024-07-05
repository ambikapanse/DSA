//https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//memoization
class Solution {
  public:
    int rec(int index, vector<vector<int>>& points, int last, vector<vector<int>>& dp){
        //base case
        if(index==0){
            int maxi=INT_MIN;
            for(int i=0;i<3;i++){
                if(i!=last)
                maxi = max(maxi, points[index][i]);
            }
            return maxi;
        }
        //check in dp
        if(dp[index][last]!=-1) return dp[index][last];
        
        //not in dp, then put in dp
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=last){
                int point = points[index][i] + rec(index-1, points, i, dp);
                maxi = max(point,maxi);
            }
        }
        return dp[index][last] = maxi;
            
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return rec(n-1, points, 3, dp);
    }
};

//tabulation
class Solution {
  public:
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        dp[0][0] = max(points[0][1], points[0][2]); 
        dp[0][1] = max(points[0][0], points[0][2]); 
        dp[0][2] = max(points[0][1], points[0][0]); 
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); 
        
        for(int day=1;day<n;day++){
            for(int last=0; last<4; last++){
                int maxi = INT_MIN;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int point = points[day][task] + dp[day-1][task];
                        maxi = max(maxi, point);
                    }
                }
                dp[day][last] = maxi;  
            }
        }
        return dp[n-1][3];
    }
};
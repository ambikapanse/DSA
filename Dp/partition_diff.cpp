//https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
  public:
  
    int mod = (int)1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        
        // we want s1 and s2 st
        // s1-s2 = d
        // since s1+s2 = totalSum
        // d+s2+s2 = totalSum
        // s2 = (totalSum-d)/2
        int totalSum = accumulate(arr.begin(),arr.end(),0);
        if(totalSum-d<0 || (totalSum-d)%2) 
            return 0;
        
        int sum = (totalSum-d)/2;
        
	    vector<vector<int>>dp(n, vector<int>(sum+1,0));
	    
	    for(int i=0;i<n;i++){
	       dp[i][0] = 1;
	    }
	    
	    if(arr[0]<=sum){
	        dp[0][arr[0]] += 1; // Use += to account for multiple zeroes
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int target=0; target<=sum; target++){
	            int incl = 0;
	            if(arr[i]<=target) incl = dp[i-1][target-arr[i]];
	            int excl = dp[i-1][target];
	            dp[i][target] = (incl+excl)%mod;
	        }
	    }
	    
	    return dp[n-1][sum];
    }
};
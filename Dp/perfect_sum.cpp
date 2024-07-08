//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem
#include<iostream>
#include<vector>
using namespace std;

class Solution{

	public:
// 	int rec(int arr[], int sum, int index){
// 	    //base case
// 	    if(sum==0) return 1;
// 	    if(index==0){
// 	        if(sum-arr[0]==0)
// 	        return 1;
// 	        return 0;
// 	    };
	    
// 	    int incl = rec(arr, sum-arr[index], index-1);
// 	    int excl = rec(arr, sum, index-1);
	    
// 	    return incl+excl;
// 	}
	int mod = (int)(1e9+7);
	
	int perfectSum(int arr[], int n, int sum)
	{   
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
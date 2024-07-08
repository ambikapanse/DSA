//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<iostream>
#include<vector>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Create a 1D array to store the maximum values for each weight capacity.
        vector<int> dp(W + 1, 0);

        // Iterate through each item and update the maximum values for each weight capacity.
        for (int i = 0; i < n; i++) {
            // Traverse the dp array in reverse to avoid considering the same item multiple times.
            for (int j = W; j >= wt[i]; j--) {
                // Calculate the maximum value if we either include the current item or skip it.
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }

        // The final answer will be in dp[W], which represents the maximum value for weight capacity W.
        return dp[W];

    }

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>>dp(n+2, vector<long>(2,0));

        //base case
        
        dp[n+1][0] = dp[n+1][1] = 0;
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                long profit;
                //buy
                if(buy==1)
                profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                //sell
                else
                profit = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
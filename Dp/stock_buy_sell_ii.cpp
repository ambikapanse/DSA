#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // int rec(vector<int>& prices, int index, int canBuy){
    //     //base case
    //     if(index==prices.size()){
    //         return 0;
    //     }
    //     long profit=0;
    //     //you can buy
    //     if(canBuy==1){
    //         //max of take - not take
    //         profit = max(-prices[index] + rec(prices, index+1, 0), 0 + rec(prices, index+1, 1));
    //     }
    //     //you cannot buy
    //     else{
    //         //max of sell - not sell
    //         profit = max(prices[index] + rec(prices, index+1, 1), 0 + rec(prices, index+1, 0));
    //     }

    //     return profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>>dp(n+1, vector<long>(2,0));

        //base case
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                long profit;
                if(buy==1)
                profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                else
                profit = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
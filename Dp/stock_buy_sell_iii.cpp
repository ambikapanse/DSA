#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rec(vector<int>& prices, int ind, int buy, int cap){
        //base case
        if(cap==0 || ind==prices.size())
        return 0;

        long profit;
        //can buy
        if(buy){
            //max of take-not take
            profit = max(-prices[ind] + rec(prices, ind+1, 0, cap),
                            0 + rec(prices, ind+1, 1, cap));
        }
        //cannot buy
        else{
            //max of sell-not sell
            profit = max(prices[ind] + rec(prices, ind+1, 1, cap-1),
                            0 + rec(prices, ind+1, 0, cap));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>>dp(n+1, vector<vector<long>>(2, vector<long>(3,0)));

        //base case
        //no need since its already set 0, just start cap from 1.
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<2; j++){
        //             dp[i][j][0] = 0;
        //     }
        // }

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    long profit = 0;
                    if(buy){
                        //max of take-not take
                        profit = max(-prices[ind] + dp[ind+1][0][cap],
                                        0 + dp[ind+1][1][cap]);
                    }
                    //cannot buy
                    else{
                        //max of sell-not sell
                        profit = max(prices[ind] + dp[ind+1][1][cap-1],
                                        0 + dp[ind+1][0][cap]);
                    }

                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};
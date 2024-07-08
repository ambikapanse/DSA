#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,min=prices[0],cost;
        
        for(int i=0;i<prices.size();i++){
            cost = prices[i]-min;
            profit = max(profit, cost);
            if(min>prices[i])
            min = prices[i];
        }
        return profit;
    }
};
//https://leetcode.com/problems/counting-bits/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1, 0);
        ans[0] = 0;
        for(int i=1; i<=n; i++){
            if(i%2!=0){
                ans[i] = ans[i/2]+1;
            }else{
                ans[i] = ans[i/2];
            }
            
        } 
        return ans;
    }
};
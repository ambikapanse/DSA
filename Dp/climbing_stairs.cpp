//https://leetcode.com/problems/climbing-stairs/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
        return 1;
        int prev2, prev, curr;
        curr = prev2 = prev = 1;
        for(int i=2; i<=n; i++){
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
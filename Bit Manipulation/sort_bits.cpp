//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [](int &a, int &b){
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            if(count_a==count_b){
                return a<b;
            }
            return count_a<count_b;
        };
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};
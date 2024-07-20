//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        //count number of flips needed to match a|b and c
        int d = (a|b)^c;
        //count the number of flips missed to be counted
        //in the case where a's and b's bits are flipped simultaneously
        int e = (a&b)&d;
        return __builtin_popcount(d)+__builtin_popcount(e);
        
    }
};
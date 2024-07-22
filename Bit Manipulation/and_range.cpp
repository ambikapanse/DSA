//https://leetcode.com/problems/bitwise-and-of-numbers-range/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftcount=0;
        //shift left, right until they become equal.
        //once they're equal, bits will remain unchanged upon AND
        while(left!=right){
            left = left>>1;
            right = right>>1;
            shiftcount++;
        }
        
        //return the left/right shifted
        //since the non-matching bits result in a 0 upon AND
        return left<<shiftcount;
    }
};

//Approach 2
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left){
            right = right&(right-1);
        }
        
        return right;
    }
};
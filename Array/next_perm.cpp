#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index=-1;
        //find the index where there's a dip, increase to decrease starting from the end
        //since the next permutation of a certain set will have more 1 more number in the set of increasing numbers
        //as seen from the end.
        //eg 2 1 5 4 3 0 0 => dip index = 1
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            index = i;
            break;
            }
        }
        //then find a number ahead of the dip index that is smaller
        //swap them
        // eg 2 3 5 4 1 0 0 
        for(int i=n-1;i>=index && index!=-1;i--){
            if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
            }
        }
        //smallest such number is reqd answer
        //swap all numbers after the dip index
        reverse(nums.begin()+index+1,nums.end());
    }
};
//https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int s=0;
        int e=nums.size()-1;

        if(nums.size()==1){
            return nums[0];
        }

        if(nums.size()==2){
            return -1;
        }
        
        while(s<e){
            int mid = s+(e-s)/2;
            //if mid is odd, shift it backwards
            if(mid%2==1){
                mid--;
            }
            //mid is an even index
            if(nums[mid]!=nums[mid+1]){
                e=mid;
            }else{
                s=mid+2;
            }
        }
        return nums[s];
    }
};
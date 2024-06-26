//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=INT_MAX;

        while(s<=e){
            int mid = s+(e-s)/2;

            //left is sorted, so minimum will be nums[s], search right half
            if(nums[s]<=nums[mid]){
                ans = min(nums[s],ans);
                s=mid+1;
            }

            //right is sorted, so minimum will be nums[mid], search left half
            else{
                ans = min(nums[mid],ans);
                e=mid-1;
            }
        }
        return ans;
    }
};
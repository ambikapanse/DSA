//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//but array has duplicates :)
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            //found target
            if(nums[mid]==target)
            return true;
            
            //since array has duplicates, problem arises for:
            //arr = [1,0,1,1,1]
            //if s and mid and e are equal
            if(nums[s]==nums[mid] && nums[mid]==nums[e]){
                s=s+1;
                e=e-1;
                continue;
            }

            //if left half is sorted
            if(nums[s]<=nums[mid]){
                //target lies between s and mid
                if(nums[s]<=target && target<=nums[mid]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
            //if right half is sorted
            else{
                //target lies betwen mid and e
                if(nums[mid]<=target && target<=nums[e]){
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
        }

        return false;
    }
};
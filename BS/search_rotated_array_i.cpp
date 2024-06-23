// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;

        while(s<=e){

            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                return mid;
            }

            //if left half is sorted
            if(nums[s]<=nums[mid]){
                //check if target lies between start and mid
                if(nums[s]<=target && target<=nums[mid]){
                    e = mid-1;
                }
                //else it lies after mid
                else
                {
                    s = mid+1;
                }
            }
            //if right half is sorted
            else{
                //check if target lies between mid and end
                if(nums[mid]<=target && target<=nums[e]){
                    s = mid+1;
                }
                //else it lies before mid
                else
                {
                    e = mid-1;
                }
            }

        }

        return -1;
    }
        
};

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        else if(nums.size()==1){
            if(nums[0]==target)
            return {0,0};
            return {-1,-1};
        }
        else{

            int s=0,f=-1,l=-1;
            int e=nums.size()-1;

            //find the first occurrence of target
            while(s<=e){
                int mid = s+(e-s)/2;
                if(nums.at(mid)==target){
                    f = mid;
                    e = mid-1;
                }
                else if(nums.at(mid)<target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            s=0;
            e=nums.size()-1;
            //find the last occurrence of target
            while(s<=e){
                int mid = s+(e-s)/2;
                if(nums.at(mid)==target){
                    l = mid;
                    s = mid+1;
                }
                else if(nums.at(mid)<target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }

            return {f,l};
        }
    }
};
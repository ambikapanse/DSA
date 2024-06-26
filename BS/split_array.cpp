//https://leetcode.com/problems/split-array-largest-sum/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //Book Allocation Problem
    int isPossible(vector<int>& nums, int n, int k, int mid){
        int subarrays=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                subarrays++;
                if(subarrays>k || nums[i]>mid){
                    return false;
                }
                sum=nums[i];
            }
        }
        return true;

    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        int s=0, e=0;
        for(int i : nums){
            e+=i;
        }
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums, n, k, mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};
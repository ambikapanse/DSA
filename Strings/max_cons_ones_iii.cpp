//https://leetcode.com/problems/max-consecutive-ones-iii/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0, r=0, cnt=0, max_len=0;
        while(r<n){
            if(nums[r]==0){
                cnt++;
            }
            if(cnt>k){
                while(nums[l]!=0 && l<n){
                    l++;
                }
                //to skip the current zero so that cnt = k
                l++;
                cnt--;
            }
            int len = r-l+1;
            max_len = max(max_len, len);
            r++;
        }

        return max_len;
    }
};
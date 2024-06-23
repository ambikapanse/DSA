// https://leetcode.com/problems/find-peak-element/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;

        if(nums.size()==1)
        return 0;

        int flag=0;
        while(s<e){

            //flag to break the loop once e==mid starts repeating
            if(flag==1)
            break;

            int mid = s+(e-s)/2;
            //if mid lies in increasing part
            if(nums[mid]<nums[mid+1]){
                s = mid+1; 
            }
            //if mid lies in the decreasing part or is the peak itself
            else{
                if(e==mid)
                flag=1;
                else
                e = mid;
            }
        }
        
        return e;
    }
};
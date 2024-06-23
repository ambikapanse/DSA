//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums.at(i));
        }
        return maxi;
    }
    int ceilSum(vector<int>& nums, int threshold,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums.at(i)/(double)mid);
            if(sum>threshold)
            return 0;
        }
        return 1;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=findMax(nums);
        int min=INT_MAX; //sum of the division results
        int ans;

        while(s<=e){
            int mid = s+(e-s)/2;
            cout<<mid<<endl;

            //if ceilSum possibly under threshold with mid
            if(ceilSum(nums,threshold,mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }

        }
        return ans;
    }
};
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/
#include<iostream>
#include<vector>
#include<climits>
#include<numeric>
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
    
    bool shipPossible(vector<int>& weights, int days, int mid){
        int sum=0,days_taken=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                days_taken++;
                sum=weights[i];
            }
            else
            sum+=weights[i];
            //if days_taken exceed days given
            if(days_taken>days){
                return 0;
            }
        }
        if(days_taken+1>days){
            return 0;
        }
        return 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //the maximum capacity required to ship 1 element in 1 day 
        int s=findMax(weights) ;
        //the max capacity possible to ship all elements in 1 day
        int e=accumulate(weights.begin(),weights.end(),0);
        int ans = e;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(shipPossible(weights, days, mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};
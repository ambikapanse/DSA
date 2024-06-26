//https://leetcode.com/problems/koko-eating-bananas/

#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles.at(i));
        }
        return maxi;
    }
    int canEat(vector<int>& piles, int h, int mid){
        int hours_taken=0;
        for(int i=0;i<piles.size();i++){
            hours_taken += ceil((double)piles.at(i)/(double)mid);
            if(hours_taken>h){
                return 0; //k or mid is too less to eat all of them.
            }
        }
        //mid is a possible answer
        if(hours_taken<=h)
        return 1;
        return 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=findMax(piles);
        int ans=INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(canEat(piles, h, mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};
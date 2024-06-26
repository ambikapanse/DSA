//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findMax(vector<int>& bloomDay){
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi = max(maxi,bloomDay.at(i));
        }
        return maxi;
    }
    int canMake(vector<int>& bloomDay, int m, int k, int mid){
        int bouquet=0;
        int flower=0;
        for(int i=0;i<bloomDay.size();i++){
            //counting adjacent flowers
            if(bloomDay[i]<=mid){
                flower++;
            }else{
                flower=0;
            }
            //counting bouquets
            if(flower==k){
                bouquet++;
                flower=0;
            }
            //required bouquets made
            if(bouquet==m)
            return 1;
        }
        return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=1;
        int e=findMax(bloomDay);
        int ans=-1;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(canMake(bloomDay,m,k,mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};
//https://leetcode.com/problems/kth-missing-positive-number/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            //check missing values at mid
            int missing = arr[mid]-mid-1;
            if(missing<k){
                s=mid+1;
            }else if(missing>=k){
                e=mid-1;
            }
        }
        //ans = arr[e] + more
        //ans = arr[e] + (k - missing)
        //ans = arr[e] + k - (arr[e] - e -1)
        //ans = e+1+k;
        //s = e+1; at the end
        int ans = e+k+1;
        return ans;
    }
};
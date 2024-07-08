#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ansStart = -1, ansEnd = -1;
        int sum=0;
        int maxi = INT_MIN;
        int start;

        for(int i=0; i<nums.size(); i++){

            if(sum==0){
                start = i;
            }
            sum += nums[i];

            if(sum>maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            if(sum<0){
                sum=0;
            }
        }
        //if we need to ouput the maximum sum
        return maxi;

        //if we need to output the subarray => ansStart to ansEnd
    }
};
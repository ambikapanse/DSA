//https://leetcode.com/problems/majority-element-ii/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2=0;
        int el1, el2;
        for(int i=0; i<nums.size(); i++){
            if(count1==0 && el2!=nums[i]){
                //set a new element
                count1=1;
                el1 = nums[i];
            }
            else if(count2==0 && el1!=nums[i]){
                //set a new element
                count2=1;
                el2 = nums[i];
            }
            else if(nums[i]==el1){
                //found the element we were counting
                count1++;
            }
            else if(nums[i]==el2){
                //found the element we were counting
                count2++;
            }
            else{
                //found another element
                count1--;
                count2--;
            }
        }

        //if a max element exists it will be el
        int cnt1=0, cnt2=0;
        for(int num : nums){
            if(num == el1)
            cnt1++;
            else if(num == el2)
            cnt2++;
        }
        vector<int>res;
        if(cnt1>nums.size()/3)
        res.push_back(el1);

        if(cnt2>nums.size()/3)
        res.push_back(el2);

        return res;    
    }
};
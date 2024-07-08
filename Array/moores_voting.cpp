#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                //set a new element
                count=1;
                el = nums[i];
            }else if(nums[i]==el){
                //found the element we were counting
                count++;
            }else{
                //found another element
                count--;
            }
        }

        //if a max element exists it will be el
        int cnt=0;
        for(int num : nums){
            if(num == el)
            cnt++;
        }

        if(cnt>nums.size()/2)
        return el;

        return -1;
    }
};
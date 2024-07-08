#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort 0s, 1s and 2s
        //assume from start to low -> 0
        // from low to mid -> 1
        // from mid tp high -> unsorted area
        // from high to end -> 2

        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }

    }
};
//https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // eg. 5,2,0,3,1
        // pref[0] = arr[0] = 5
        // pref[1] = arr[0] ^ arr[1] = 2
        // pref[1] = pref[0] ^ arr[1]
        // => arr[1] = pref[1] ^ pref[0]
        // pref[2] = arr[0] ^ arr[1] ^ arr[2] = 0
        // pref[2] = pref[1] ^ arr[2] = 0
        // => arr[2] = pref[2] ^ pref[1]

        // arr[i] = pref[i] ^ pref[i-1]
        for(int i=pref.size()-1; i>0; i--){
            pref[i] = pref[i] ^ pref[i-1];
        }

        return pref;
    }
};
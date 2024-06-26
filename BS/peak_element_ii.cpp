// https://leetcode.com/problems/find-a-peak-element-ii/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int findMax(vector<vector<int>>& mat, int mid){
        int ind=-1,maxi=INT_MIN;
        for(int i=0;i<mat.size();i++){
            if(maxi<mat[i][mid]){
                maxi = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s=0;
        int e=mat[0].size()-1;
        int m = mat[0].size();
        while(s<=e){
            int mid = s+(e-s)/2;
            int maxRowIndex = findMax(mat,mid);
            int left = mid-1>=0?mat[maxRowIndex][mid-1]:-1;
            int right = mid+1<m?mat[maxRowIndex][mid+1]:-1;

            if(left<mat[maxRowIndex][mid] && mat[maxRowIndex][mid]>right){
                return {maxRowIndex,mid};
            }
            else if(left>mat[maxRowIndex][mid]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return {-1,-1};
    }
};
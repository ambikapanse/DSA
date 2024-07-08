//https://leetcode.com/problems/rotate-image/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose + reverse each row
        int n = matrix.size();
        //transpose
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i!=j)
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse each row
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};
//https://leetcode.com/problems/spiral-matrix/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> result;
        int total = rows*cols;
        int firstRow = 0;
        int firstCol = 0;
        int lastRow = rows-1;
        int lastCol = cols-1;
        int count = 0;

        while(total>count){
            for(int i=firstCol; count<total && i<=lastCol; i++){
                result.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;

            for(int i=firstRow; count<total && i<=lastRow; i++){
                result.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;

            for(int i=lastCol; count<total && i>=firstCol; i--){
                result.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;

            for(int i=lastRow; count<total && i>=firstRow; i--){
                result.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
        }
        return result;
    }
};
//https://leetcode.com/problems/score-after-flipping-matrix/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        //rows
        for(int i=0; i<grid.size(); i++){
            //flip a row if the first element is zero
            if(grid[i][0]==0){
                for(int j=0; j<grid[0].size(); j++){
                    grid[i][j] = 1 - grid[i][j];
                }

            }
        }

        //columns
        for(int j=1; j<grid[0].size(); j++){
            //flip a column if no. of zeroes > no. of ones
            int cntZero=0, cntOne=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==0){
                    cntZero++;
                }
            }
            cntOne = grid.size() - cntZero;
            if(cntZero>cntOne){
                for(int i=0;i<grid.size(); i++)
                    grid[i][j] = 1 - grid[i][j];
            }
        }

        //calculate sum
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[0].size(); j++){
                int val = grid[i][j] * pow(2, (grid[0].size() - j - 1));
                sum+=val;
            }
        }

        return sum;    

    }
};
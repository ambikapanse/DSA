// 1
// 1 1 
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int row) {
        int element = 1;
        vector<int> ans;
        ans.push_back(1);
        for(int col=1;col<row;col++) {
            element = element * (row - col);
            element = element / col;
            ans.push_back(element);
        }
        return ans;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1;row<=numRows;row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};
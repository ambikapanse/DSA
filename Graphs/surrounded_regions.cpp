
//https://leetcode.com/problems/surrounded-regions/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void f(vector<vector<char>>& board, int r, int c){
        board[r][c] = '$';
        int drow[] = {-1, 0 , +1, 0};
        int dcol[] = {0, -1 , 0, +1};
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]=='O'){
                f(board, nrow, ncol);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(), 0));
        for(int i=0; i<board.size(); i++){
            if(board[i][0]=='O'){
                f(board, i, 0);
            }
            if(board[i][board[0].size()-1]=='O'){
                f(board, i, board[0].size()-1);
            }
        }

        for(int j=0; j<board[0].size(); j++){
            if(board[0][j]=='O'){
                f(board, 0, j);
            }
            if(board[board.size()-1][j]=='O'){
                f(board, board.size()-1, j);
            }
        }
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='$'){
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    
    }
};

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> zigzagTraversal(TreeNode* root){
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    //flag for left ot right
    int leftToRight = 1;

    while(!q.empty()){
        int size = q.size();
        vector<int>level(size,0);
        for(int i=0; i<size; i++){
            int node = q.front();
            q.pop();
            if(leftToRight){
                level[i] = node->val;
            }else{
                level[size-i-1] = node->val;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }

    return ans;
}
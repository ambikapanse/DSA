#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bottomView(TreeNode* root){
    //{line} -> {node.val}
    map<int,int>mp;
    vector<int>ans;
    //{node, line}
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int line = p.second;
        map[line] = node->val;

        if(node->left){
            q.push(node->left, line-1);
        }
        if(node->right){
            q.push(node->right, line+1);
        }
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }

    return ans;
}
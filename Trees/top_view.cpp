#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topView(TreeNode* root){
    vector<int>ans;
    //{line} -> {node.value}
    map<int,int>mp;
    //{node, line}
    queue<pair<TreeNode*, int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int line = p.second;
        //if the first element of a certain vertical line not in map, add it 
        if(mp.find(line)==mp.end()) mp[line] = node->val;

        if(node->left){
            q.push({node->left,line-1});
        }
        if(node->right){
            q.push({node->right,line+1});
        }
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }

    return ans;
}


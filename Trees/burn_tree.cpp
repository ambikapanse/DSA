#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int burnTree(TreeNode* root, TreeNode* target){
    //mark the parents for all nodes
    unordered_map<TreeNode*,TreeNode*>parent_track;
    queue<TreeNode*>tempq;
    tempq.push(root);
    while(!tempq.empty()){
        TreeNode* node = tempq.front();
        tempq.pop();
        if(node->left){
            parent_track[node->left] = node;
            tempq.push(node->left);
        }
        if(node->right){
            parent_track[node->right] = node;
            tempq.push(node->right);
        }
    }

    //bfs
    queue<TreeNode*>q;
    q.push(target);
    unordered_map<TreeNode*, bool>visited;
    visited[target] = true;
    int ans=0;

    while(!q.empty()){
        int size = q.size();
        int fl=0;
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                visited[node->left] = true;
                q.push(node->left);
                fl=1;
            }
            if(node->right && !visited[node->right]){
                visited[node->right] = true;
                q.push(node->right);
                fl=1;
            }
            if(parent[node] && !visited[parent[node]]){
                visited[parent[node]] = true;
                q.push(parent[node]);
                fl=1;
            }
        }
        if(fl) ans++;
    }

    return ans;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//
//          3
//        /   \ 
//       /     \ 
//      5        1
//    /   \    /   \ 
//   6     2  0     8
//       /   \ 
//      7     4
// given target = 5, k=2 print all nodes at a distance k from target
// o/p = [1,4,7]
// 1. have parent pointers for all nodes
// 2. iterate the distance k no. of times

vector<int> kDistNodes(TreeNode* root, TreeNode* target, int k){
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

    //bfs for k times
    queue<TreeNode*>q;
    q.push(target);
    unordered_map<TreeNode*, bool>visited;
    visited[target] = true;
    int curr_level = 0;

    while(!q.empty()){
        if(curr_level++ == k) break;
        int size = q.size();
        
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                visited[node->left] = true;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                visited[node->right] = true;
                q.push(node->right);
            }
            if(parent[node] && !visited[parent[node]]){
                visited[parent[node]] = true;
                q.push(parent[node]);
            }
        }
    }

    vector<int>ans;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        ans.push_back(curr->val);
    }

    return ans;
    


}
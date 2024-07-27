#include<iostream>
#include<vector>
using namespace std;

bool isLeaf(TreeNode* node){
    if(!node->left && !node->right){
        return true;
    }
    return false;
}

vector<int> leftBoundary(TreeNode* root){
    vector<int>left;
    TreeNode* curr = root;
    while(curr){
        if(!isLeaf(curr)) left.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

vector<int> leafBoundary(TreeNode* root, vector<int>& leaves){
    if(ifLeaf(root)){
        leaves.push_back(root->val);
    }
    leafBoundary(root->left, leaves);
    leafBoundary(root->right, leaves);
}

vector<int> rightBoundary(TreeNode* root){
    vector<int>right;
    TreeNode* curr = root->right;
    while(curr){
        if(!isLeaf(curr)) right.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

#include<iostream>
#include<vector>
using namespace std;

vector<int>rView;
void rightView(TreeNode* node, int level, vector<int>& rView){
    if(node==NULL)
    return;

    if(level == rView.size()){
        rView.push_back(node->val);
    }

    rightView(node->right, level+1, rView);
    rightView(node->left, level+1, rView);
}

vector<int>lView;
void leftView(TreeNode* node, int level, vector<int>& lView){
    if(node==NULL)
    return;

    if(level == lView.size()){
        lView.push_back(node->val);
    }

    leftView(node->left, level+1, lView);
    leftView(node->right, level+1, lView);
}
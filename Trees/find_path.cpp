#include<iostream>
#include<vector>
using namespace std;

//call -> getPath(root, 7, arr)
bool getPath(TreeNode* node, int x, vector<int>& arr){
    if(!node){
        return false;
    }

    arr.push_back(node->val);

    if(node->val == x){
        return true;
    }

    if(getPath(node->left, x, arr) || getPath(node->right, x, arr)){
        return true;
    }

    arr.pop_back();
    return false;
}
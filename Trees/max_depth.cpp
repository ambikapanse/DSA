#include<iostream>
#include<vector>
using namespace std;

int maxDepth(TreeNode* node){
    if(node==NULL){
        return 0;
    }

    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);

    return 1+max(lh,rh); 
}
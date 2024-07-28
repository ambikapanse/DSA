//lowest common ancestor of two given nodes
#include<iostream>
#include<vector>
using namespace std;

//call -> lca(root, node1, node2); returns lca of node1 and node2
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    //base case
    if(root==NULL||root==p||root==q){
        return root;
    }
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    //result
    if (left==NULL){
        return right;
    }
    else if (right==NULL){
        return left;
    }
    else{ //both left and right are not null, we found our result
        return root;
    }
}
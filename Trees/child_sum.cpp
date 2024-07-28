#include<iostream>
#include<vector>
using namespace std;

//          40
//       /      \ 
//      10      20
//    /   \    /   \ 
//   2     5 30     40
//convert the given tree such that all nodes are sum of their left and right child => can only increase the value of a node
//          150
//       /      \ 
//      80      70
//    /   \    /   \ 
//   40    40 30    40
// when moving down, if left+right < parent => make left.val = right.val = parent.val
// when leaf nodes are replaced as well, start moving up => make all parent.val = left.val+right.val
// when moving down, if left+right >= parent => make parent.val = left.val+right.val
// start moving up => parent.val = left.val+right.val


void convertChildSum(TreeNode* node){
    if(!node){
        return;
    }

    int sum=0;
    if(node->left) sum += node->left->val;
    if(node->right) sum += node->right->val;

    if(node->val > sum){
        if(node->left) node->left->val = node->val;
        if(node->right) node->right->val = node->val;
    }else{
        node->val = sum;
    }

    convertChildSum(node->left);
    convertChildSum(node->right);

    int updateSum=0;
    if(node->left) updateSum += node->left->val;
    if(node->right) updateSum += node->right->val;
    if(node->left || node->right)
    node->val = updateSum;
}
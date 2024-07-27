#include<iostream>
#include<vector>
using namespace std;

int maxSum = 0;

int maxDepth(TreeNode* node, int& maxSum){
    if(node==NULL){
        return 0;
    }

    //we don't consider the value of a node that's negative
    int lsum = max(0,maxDepth(node->left,maxSum));
    int rsum = max(0,maxDepth(node->right,maxSum));

    int sum = node->val + lsum + rsum;
    maxSum = max(maxSum, sum);

    return node->val + max(lsum,rsum); 
}
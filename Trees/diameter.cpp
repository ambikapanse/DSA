#include<iostream>
#include<vector>
using namespace std;
//O(N),O(N) -> based on masDepth recursion
int diameter = 0;
int maxDepth(TreeNode* node, int& diameter){
    if(node==NULL){
        return 0;
    }

    int lh = maxDepth(node->left, diameter);
    int rh = maxDepth(node->right, diameter);

    diameter = max(diameter, lh+rh); 
    return 1+max(lh,rh); 
}
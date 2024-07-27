#include<iostream>
#include<vector>
using namespace std;


//USING MAX DEPTH
//if balanced -> return -1 else return height
int maxDepth(TreeNode* node){
    if(node==NULL){
        return 0;
    }

    int lh = maxDepth(node->left);
    if(lh==-1) return -1;
    int rh = maxDepth(node->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh); 
}


//NAIVE SOLUTION
int heightLeft(TreeNode* node){
    if(node==NULL)
    return 0;

    return 1+heightLeft(node->left);
}

int heightRight(TreeNode* node){
    if(node==NULL)
    return 0;

    return 1+heightRight(node->right);
}

bool checkBalanced(TreeNode* node){
    if(node==NULL){
        return true;
    }

    int lh = heightLeft(node);
    int rh = heightRight(node);
    if(abs(lh-rh)>1) return false;

    bool leftTree = checkBalanced(node->left);
    bool rightTree = checkBalanced(node->right);
    if(!left || !right) return false;
    return true;
}
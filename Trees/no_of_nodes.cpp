//number of nodes in a complete BT
#include<iostream>
#include<vector>
using namespace std;


//the number of nodes in a perfectly complete BT = 2^h-1       {h=height}
//if the BT is not perfectly complete, call the function for left and right subtree separately


int countNode(TreeNode* node){
    if(node==NULL) return 0;

    int lh = lHeight(node);
    int rh = lHeight(node);

    if(lh==rh){
        return (1<<lh)-1;
    }
    else{
        return 1+countNode(node->left)+countNode(node->right);
    }
}
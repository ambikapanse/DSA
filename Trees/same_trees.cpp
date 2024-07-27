#include<iostream>
#include<vector>
using namespace std;

bool checkSame(TreeNode* p, TreeNode* q){
    if(p==NULL || q==NULL){
        return (p==q);
    }

    return (p->val==q->val)
        && checkSame(p->left, q->left) 
        && checkSame(p->right, q->right);
}
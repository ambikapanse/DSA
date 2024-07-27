#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> allTraversals(TreeNode* root){
    vector<int>pre,in,post;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        TreeNode* node = st.top().first;
        int num = st.top().second;
        st.pop();
        if(num==1){
            pre.push_back(node->val);
            num++;
            st.push({node,num});
            if(node->left!=NULL){
                st.push({node,1});
            }
        }
        else if(num==2){
            in.push_back(node->val);
            num++;
            st.push({node,num});
            if(node->right!=NULL){
                st.push({node,1});
            }
        }else{
            post.push_back(node->val);
        }
    }
}
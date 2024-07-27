#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//root left right
vector<int> preOrder(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);
        ans.push_back(node->val);
    }

    return ans;
}

//left root right
vector<int> inOrder(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>st;
    TreeNode* node = root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left; //go to left most child, keep pushing all nodes till then into stack
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            ans.push_back(node->val); //if left child==NULL, print the root & pop, then look for right child
            node = node->right;
        }
    }

    return ans;
}

//left right root
vector<int> postOrder(TreeNode* root){
    vector<int>ans;
    stack<TreeNode*>st1, st2; //using two stacks
    st1.push(root);
    while(!st1.empty()){
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL) st1.push(node->left);
        if(node->right!=NULL) st1.push(node->right);
    }

    while(!st2.empty()){
        TreeeNode* node = st2.top();
        st2.pop();
        ans.push_back(node->val);
    }

    return ans;
}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// zero based indexing of a tree
//         i
//       /   \ 
//    2*i+1  2*i+2
//         0
//       /   \ 
//      1     2
//    /   \ /   \ 
//   3    4 5    6
// width here = 6-3+1

int width(TreeNode* root){
    int ans=0;
    //{node, index}
    queue<pair<TreeNode*,int>>q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int minind = q.front().second; //minimum index in that particular level
        int first,last;
        for(int i=0; i<size;i++){
            TreeNode* node = q.front().first;
            int ind = q.front().second - minind; //to handle overflow of index
            q.pop();
            if(i==0) first = ind;
            if(i==size-1) last = ind;

            if(node->left){
                q.push({node->left, 2*ind+1});
            }
            if(node->right){
                q.push({node->right, 2*ind+2});
            }
        }
        ans = max(ans,last-first+1);
    }

    return ans;

}




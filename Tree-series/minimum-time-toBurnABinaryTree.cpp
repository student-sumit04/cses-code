#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;


class TreeNode{
    public:

    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        data=val;
        left=right=nullptr;
    }

};
void parents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mpp){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
         TreeNode*curr=q.front();
         q.pop();
         if(curr->left){
            mpp[curr->left]=curr;
            q.push(curr->left);
         }
         if(curr->right){
            mpp[curr->right]=curr;
            q.push(curr->right);
         }

    }

   

}
int minimumTime(TreeNode*root){
    queue<TreeNode*>q;
    unordered_map<TreeNode*,TreeNode*>mpp;


}

signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->right->right->left=new TreeNode(8);

}

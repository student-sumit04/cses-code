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
TreeNode*lca(TreeNode*root,TreeNode*p,TreeNode*q){
    if(root==nullptr)return nullptr;

    int curr=root->data;
    if(curr<p->data && curr<q->data){
        return lca(root->right,p,q);
    }
    if(curr>p->data && curr>q->data){
        return lca(root->left,p,q);
    }
    return root;
}


int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

  TreeNode* ans = lca(root, root->right->left, root->right->right);
if (ans) cout << ans->data << endl;
else cout << "LCA not found" << endl;
    

    

    return 0;

   
}
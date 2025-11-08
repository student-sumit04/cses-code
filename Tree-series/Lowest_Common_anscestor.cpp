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
TreeNode*lca(TreeNode*root,TreeNode* p,TreeNode* q){
    if(root==nullptr || p==root || q==root)return root;

    TreeNode*left=lca(root->left,p,q);
    TreeNode*right=lca(root->right,p,q);

    if(left==nullptr)return right;
    if(right==nullptr)return left;

    return root;





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

     TreeNode* p = root->right->left;       // node 6
    TreeNode* q = root->right->right->left;//8
    TreeNode*ans=lca(root,p,q);
    cout<<ans->data<<endl;

}
//the time complexity is O(n) and space complexity is O(n);
//here i am using the dfs technique
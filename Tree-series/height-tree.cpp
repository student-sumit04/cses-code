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
int height(TreeNode*root){
    if(root==nullptr)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int ans=height(root);
    cout<<ans<<endl;

}
//the time complexity is O(n) and space complexity is O(n)
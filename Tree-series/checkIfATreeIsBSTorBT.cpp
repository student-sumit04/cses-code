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
bool check(TreeNode*root,int minval,int maxval){
    if(root==nullptr)return true;
    if(root->data>=maxval || root->data<=minval)return false;

    return check(root->left,minval,root->data)&& check(root->right,root->data,maxval);

}
bool isvalidBST(TreeNode*root){
    return check(root,INT_MIN,INT_MAX);
}


int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    bool test=isvalidBST(root);
    if(test){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    

    return 0;

   
}
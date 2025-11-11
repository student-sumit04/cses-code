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
bool isleaf(TreeNode*root){
    if (root == nullptr) return false;
    return (!root->left)&& (!root->right);

}
void addleftboundary(TreeNode*root,vt<int>&res){
    TreeNode*curr=root->left;
    while(curr!=nullptr){
        if(!isleaf(curr))res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;

    }

}
void addrightboundary(TreeNode*root,vt<int>&res){
    TreeNode*curr=root->right;
    vt<int>temp;
    while(curr){
        if(!isleaf(curr))temp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    for(int i=(int)temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }

}
void addleaves(TreeNode*root,vt<int>&res){//inorder traversal
    if (!root) return;
    if(isleaf(root)){
        res.push_back(root->data);
        return ;
    }
    if(root->left)addleaves(root->left,res);
    if(root->right)addleaves(root->right,res);


}
vt<int>boundarytraversal(TreeNode*root){
    vt<int>res;
    if(root==nullptr)return res;

    if(!isleaf(root))res.push_back(root->data);

    addleftboundary(root,res);
    addleaves(root,res);
    addrightboundary(root,res);
    
    return res;
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
    vt<int>ans=boundarytraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

}
//the time complexity is 4*O(n) and space complexity is O(n);
// this traversal is anti clockwise , also can be done using clockwise traversal

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
vt<int>getinorder(TreeNode*root){
    vt<int>inorder;
    TreeNode*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr;
                //in preorder just one change   inorder.push_back(curr->data);
                curr=curr->left;
            }
            else{//means thread is present here
                prev->right=nullptr;
                inorder.push_back(curr->data);//not here in preorder traversal using morris traversal
                curr=curr->right;
            }
        }
    }
    return inorder;
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
    vt<int>ans=getinorder(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
//the time complexity is O(n) and space complexity is O(1)
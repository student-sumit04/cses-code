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

TreeNode*insertnode(TreeNode*root,int val){
    if(root==nullptr)return new TreeNode(val);
    TreeNode* curr=root;
    while(true){
        if(curr->data<=val){
            if(curr->right!=nullptr){
                curr=curr->right;
            }
            else{
                curr->right=new TreeNode(val);
                break;
            }
        }
        else{
            if(curr->left!=nullptr){
                curr=curr->left;
            }
            else{
                curr->left=new TreeNode(val);
                break;
            }
        }
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

    int val=9;
    TreeNode*ans=insertnode(root,val);
    cout << "Inserted: " << val << "\n";
    cout << "Root value: " << ans->data << "\n";

    return 0;

   
}
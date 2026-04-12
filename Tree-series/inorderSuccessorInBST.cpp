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
TreeNode*successor(TreeNode*root,TreeNode*p){
   TreeNode* success=nullptr;
   while(root!=nullptr){
    if(p->data>=root->data){
        root=root->right;
    }
    else{
        success=root;
        root=root->left;
    }
   }
   return success;

    
}


int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    TreeNode*ans=successor(root,root->left);
    cout<<ans->data<<endl;

 
    

    

    return 0;

   
}
//the time complexity for this approach is O(H) , also can be solved using the inorder traversal in O(n) time complexity 
//in bst inorder is sorted
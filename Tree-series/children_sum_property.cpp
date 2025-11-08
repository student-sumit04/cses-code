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
class solution{

 public:
  void reorder(TreeNode*root){
    if(root==nullptr)return ;

    int child=0;
  if(root->left)  child+=root->left->data;
  if(root->right)child+=root->right->data;

  if(child>root->data)root->data=child;

  else{
    if(root->left)root->left->data=root->data;
    else if(root->right)root->right->data=root->data;

  }
  reorder(root->left);
  reorder(root->right);

  int sum=0;
  if(root->left)sum+=root->left->data;
  if(root->right)sum+=root->right->data;
  if(root->left || root->right)root->data=sum;

  }
};
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
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

     cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    solution sol;
     sol.reorder(root);
    

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;



}
//in this approach we use the strategy of up to down then again down to up with all modification allowed to keep the children sum property 
//root=left+right and in the question it is given that we can increase the by 1 any no of times here


//the time complexity is O(n) and space complexity is O(n)

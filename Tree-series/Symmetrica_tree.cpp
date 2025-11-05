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
bool checknew(TreeNode*root1,TreeNode*root2){
    if(root1==nullptr || root2==nullptr)return root1==root2;
    if(root1->data!=root2->data)return false;

    return checknew(root1->left,root2->right) && checknew(root1->right,root2->left);

}
bool check(TreeNode*root){
    return root==nullptr || checknew(root->left,root->right);
    

}

signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    bool test=check(root);
    cout<<test<<endl;
    
   
  
   

}
//the time complexity is O(n)  and space complexity is O(n)
//symmetric means mirror image 
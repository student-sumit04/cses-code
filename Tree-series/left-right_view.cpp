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
void solve(TreeNode*root,vt<int>&res,int level){
    if(root==nullptr)return;
    if(res.size()==level)res.push_back(root->data);
    solve(root->right,res,level+1);
     solve(root->left,res,level+1);


}
vt<int> rightview(TreeNode*root){
    vt<int>res;
    solve(root,res,0);
    return res;
   


    
    

}


signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vt<int>ans=rightview(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
   
  
   

}
//this is the recursive approach because iterative approach will be lengthy to code
// for the left view the left recursion be on upper side and vice versa

//the time complexity is O(n) and O(h);

//


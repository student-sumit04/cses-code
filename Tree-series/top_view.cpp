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
vt<int> topview(TreeNode*root){
    vt<int>top;

    if(root==nullptr)return top;
    map<int,int>mpp;
   queue<pair<TreeNode*,int>>q;
   q.push({root,0});
   while(!q.empty()){
    auto it=q.front();
    q.pop();
    TreeNode*node=it.first;
    int line=it.second;
    if(mpp.find(line)==mpp.end())mpp[line]=(node->data);

    if(node->left)q.push({node->left,line-1});
    if(node->right)q.push({node->right,line+1});

   }
   for(auto it:mpp){
    top.push_back(it.second);
   }
   return top;


    
    

}


signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vt<int>ans=topview(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
  
   

}
//here we are using the level order traversal for traversing the tree along with map to store the values as follows like ({vertical,node})
//the time complexity is O(n) and O(n);
//queue is storing ({node,vertical});
//recursive approach will not be preferable here because along with it height concept will also be used , it will be messy here


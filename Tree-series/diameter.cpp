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
int height(TreeNode*&root,int &diameter){
    if(root==nullptr)return 0;
   
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);
   
   diameter =max(diameter,lh+rh);
    return 1+max(lh,rh);
   
}

int diameter(TreeNode*root){
    int diam=0;
    height(root,diam);
    return diam;

}


signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int answer=diameter(root);
    cout<<answer<<endl;

}
///the diameter is the longest path between 2 nodes
//there is a brute force approach also possible with time complexity O(n^2)

//but this approach time complexity is O(n) and O(n)
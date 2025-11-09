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
int maximumwidth(TreeNode*root){
    if(root==nullptr)return 0;
    int ans=0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int sz=q.size();
        int min=q.front().second;
        int first=0,last=0;
        for(int i=0;i<sz;i++){
            int currid=q.front().second-min;
            TreeNode*node=q.front().first;
            q.pop();
            if(i==0)first=currid;
            if(i==sz-1)last=currid;
            if(node->left)q.push({node->left,currid*2+1});
            if(node->right)q.push({node->right,currid*2+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;
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

    cout << "Maximum width = " << maximumwidth(root) << endl;
}

//the function is optimised so that no overflow occur due to 2 power 
// the time complexity is O(n) and O(n)
//this question is to revise for more times
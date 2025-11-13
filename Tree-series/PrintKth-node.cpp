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
void  markparents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*curr=q.front();
        q.pop();
        if(curr->left){
            mpp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            mpp[curr->right]=curr;
            q.push(curr->right);
        }
    }

}
vt<int>distance(TreeNode*root,TreeNode*target,int k){
    unordered_map<TreeNode*,TreeNode*>mpp;
    markparents(root,mpp,target);
    unordered_map<TreeNode*,bool>vis;
    queue<TreeNode*>q;
    q.push(target);
    vis[target]=true;
    int level=0;
    while(!q.empty()){
        int sz=q.size();
        if(level++==k)break;
        for(int i=0;i<sz;i++){
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=true;
            }
             if(curr->right && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=true;
            }
            if(mpp[curr] && !vis[mpp[curr]]){
                q.push(mpp[curr]);
                vis[mpp[curr]]=true;
            }
        }
    }
    vt<int>res;
    while(!q.empty()){
        TreeNode*curr=q.front();
        q.pop();
        res.push_back(curr->data);
    }
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
    vt<int>ans=distance(root,root->right->right,2);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

}
//in this approach one bfs for marking the parents and another bfs for traversal in the three directions from the target upto k levels
// the time complexity is O(n)+O(n) and space complexity is O(n) +O(n)
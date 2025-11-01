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
vt<vt<int>>levelordertraversal(TreeNode* &root){
    vt<vt<int>>ans;
    if(root==nullptr)return ans;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vt<int>level;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=nullptr)q.push(node->left);
            if(node->right)q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
signed main(){

    // build a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vt<vt<int>> ans = levelordertraversal(root);

    // print result
    for(auto &level : ans){
        for(int val : level) cout << val << " ";
        cout << endl;
    }

    return 0;
}
//the time complexity will be O(n) and space complexity is O(n);
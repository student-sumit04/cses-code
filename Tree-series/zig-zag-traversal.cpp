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

vt<vt<int>>zigzagtraversal(TreeNode*root){
    vt<vt<int>>ans;
    if(root==nullptr)return ans;

    bool lefttoright=true;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        vt<int>temp(sz);
       for(int i=0;i<sz;i++){
        TreeNode*node=q.front();
        q.pop();

        int ind=(lefttoright)?i:sz-i-1;
        temp[ind]=node->data;
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);

       }
       lefttoright=!lefttoright;
       ans.push_back(temp);
    }
    return ans;
}





signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vt<vt<int>>ans=zigzagtraversal(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
//the time complexity is O(n) and space complexity is O(n)

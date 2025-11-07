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

vt<int>postordertraversal(TreeNode*root){
    stack<TreeNode*>st1;
     stack<TreeNode*>st2;
    vt<int>postorder;

    if(root==nullptr)return postorder;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)st1.push(root->left);
        if(root->right)st1.push(root->right);



    }
    while(!st2.empty()){
        TreeNode*node=st2.top();
        st2.pop();
        postorder.push_back(node->data);
    }
    return postorder;


}
signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vt<int>ans=postordertraversal(root);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
//the complexity using the two stack is O(n) and space complexity is O(2*n);


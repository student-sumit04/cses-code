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
vt<int>preorder(TreeNode*root){
    vt<int>preorder;
    if(root==nullptr)return preorder;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right)st.push(root->right);
        if(root->left)st.push(root->left);


    }
    return preorder;
}

signed main(){

    // build a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vt<int>preordertraversal=preorder(root);

    for(auto it:preordertraversal){
        cout<<it<<" ";

    }
    cout<<endl;


}
//the time complexity is O(n) and space complexity is O(n);
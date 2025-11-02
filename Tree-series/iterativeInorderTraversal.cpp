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
vt<int>inordertraversal(TreeNode*root){
    vt<int>inorder;
    if(root==nullptr)return inorder;

    stack<TreeNode*>st;
     TreeNode* node=root;
    while(true){
        if(node!=nullptr){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()==true)break;
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    return inorder;
}
signed main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vt<int>inorder=inordertraversal(root);
    for(auto it:inorder){
        cout<<it<<" ";
    }
    cout<<endl;

}
//the time complexity is O(n) && space complexity is O(n);
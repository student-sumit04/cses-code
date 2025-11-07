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
    vt<int>postorder;
    stack<TreeNode*>st;
    if(root==nullptr)return postorder;
    TreeNode*curr=root;

    while(curr!=nullptr || !st.empty()){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            TreeNode*temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }

        }
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
//the time complexity is O(n) and  space complexity is O(n).
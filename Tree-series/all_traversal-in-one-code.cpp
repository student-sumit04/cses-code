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
vt<vt<int>>alltraversal(TreeNode*root){
    vt<int>inorder,preorder,postorder;
    if(root==nullptr)return {inorder,preorder,postorder} ;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    while(!st.empty()){
       auto it=st.top();
       st.pop();
       if(it.second==1){inorder.push_back(it.first->data);//2 for preorder  //1 for inorder // 3 for postorder
       it.second++;
       st.push(it);
       if(it.first->left)st.push({it.first->left,1});
       }
       else if(it.second==2){
        preorder.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->right)st.push({it.first->right,1});
       }
       else{
        postorder.push_back(it.first->data);

       }


    }
    return {inorder,preorder,postorder};


}

signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

     vector<vector<int>> ans = alltraversal(root);

    cout << "Preorder: ";
    for(int x : ans[0]) cout << x << " ";
    cout << "\nInorder: ";
    for(int x : ans[1]) cout << x << " ";
    cout << "\nPostorder: ";
    for(int x : ans[2]) cout << x << " ";


}
//the time complexity is O(3n) and space complexity is O(4*n)

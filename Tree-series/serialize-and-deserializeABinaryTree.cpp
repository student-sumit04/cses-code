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
string serialize(TreeNode*root){
    if(!root)return "";
    string s="";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*curr=q.front();
        q.pop();
        if(curr==nullptr)s.append("# ,");
        else s.append(to_string(curr->data)+" , ");
        if(curr!=nullptr){
             q.push(curr->left);
           q.push(curr->right);

        }
       


    }
    return s;
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
    string res=serialize(root);
    cout<<res<<endl;

}
//the time  complexity is O(n) and 

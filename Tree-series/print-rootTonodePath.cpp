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
bool getPath(TreeNode*root,vt<int>&arr,int b){
    int n=arr.size();
    if(root==nullptr)return false;
    arr.push_back(root->data);
    if(root->data==b)return true;
    if(getPath(root->left,arr,b)|| getPath(root->right,arr,b))return true;

    arr.pop_back();
    return false;
}
vt<int>solution(TreeNode*root, int b){
    vt<int>ans;
    if(root==nullptr)return ans;

    getPath(root,ans,b);
    return ans;
}

signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left=new TreeNode(6);
    vt<int>res=solution(root,6);
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;

}
//the time complexity is O(n) and space complexity is O(h)

//O(h) because (height of recursion stack + path storage)
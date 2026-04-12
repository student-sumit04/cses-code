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
void printPreorder(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
TreeNode* build(vt<int>&a,int &i,int bound){
    if(i==a.size() || a[i]>bound)return nullptr;

    TreeNode*root=new TreeNode(a[i++]);
    root->left=build(a,i,root->data);
    root->right=build(a,i,bound);
    return root;
}
TreeNode* bstFromPreorder(vt<int>&a){
    int i=0;
    return build(a,i,INT_MAX);
}



int main(){
    vt<int>a={8,5,1,7,10,12};
    TreeNode*ans=bstFromPreorder(a);
    printPreorder(ans);
    cout<<endl;
   

  

    

    return 0;

   
}
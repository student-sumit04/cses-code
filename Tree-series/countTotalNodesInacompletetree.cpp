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
int findheightleft(TreeNode*node){
    int hgt=0;
    while(node){
        hgt++;
        node=node->left;
    }
    return hgt;

}
int findheightright(TreeNode*node){
    int hgt=0;
    while(node){
        hgt++;
        node=node->right;
    }
    return hgt;

}
int countnodes(TreeNode*root){
    if(root==nullptr)return 0;
    int cntleft=findheightleft(root);
    int cntright=findheightright(root);

     if(cntleft==cntright)return ((1<<cntleft)-1);

    return 1+countnodes(root->left)+countnodes(root->right);
}

signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    //root->right->right->left=new TreeNode(8);
    int num=countnodes(root);
    cout<<num<<endl;

}
//All nodes in levels 1 to (h−1) are full (each node has 2 children).

// On the last level:

// There may be some missing nodes.

// But missing nodes can only appear on the right side, never in the middle.

// the time complexity is O(n) and space complexity is O(h);
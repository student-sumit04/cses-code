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

int floor(TreeNode*root,int key){
    int res=-1;
    while(root){
        if(root->data==key){
            res=root->data;
            return res;
        }
        if(key>root->data){
             res=root->data;
            root=root->right;
        }
        else{
           
            root=root->left;
        }
    }
    return res;




}
int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int target;
    cin >> target;

    int ans = floor(root, target);
    cout << ans << endl;

    return 0;
}
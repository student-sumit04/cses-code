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

TreeNode* prevNode = nullptr;

void flatten(TreeNode* root) {
    if (root == nullptr) return ;
    flatten(root->right);
    flatten(root->left);
    root->right = prevNode;
    root->left = nullptr;
    prevNode = root;
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
    flatten(root);

    // Print the flattened tree
    TreeNode* curr = root;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;

}
//the time complexity is O(n) and O(n)
//this is the recursive approach also we can solve this using iterative approach
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

TreeNode* searchBST(TreeNode* root ,int val){
    while(root!=nullptr && root->data!=val){
        root= (val<root->data)?root->left:root->right;
    }
    return root;
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

    TreeNode* ans = searchBST(root, target);
    if (ans != nullptr) {
        cout << "Found: " << ans->data << "\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
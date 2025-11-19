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
        if(curr==nullptr)s.append("#,");
        else s.append(to_string(curr->data)+",");
        if(curr!=nullptr){
             q.push(curr->left);
           q.push(curr->right);

        }
       


    }
    return s;
}


TreeNode* deserialize(const string &data){
    if(data.empty()) return nullptr;

    stringstream ss(data);
    string token;

    // Read root value
    getline(ss, token, ',');
    if(token == "#" || token.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(token));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        // ----- LEFT CHILD -----
        if(!getline(ss, token, ',')) break;
        if(token != "#"){
            TreeNode* left = new TreeNode(stoi(token));
            node->left = left;
            q.push(left);
        } else {
            node->left = nullptr;
        }

        // ----- RIGHT CHILD -----
        if(!getline(ss, token, ',')) break;
        if(token != "#"){
            TreeNode* right = new TreeNode(stoi(token));
            node->right = right;
            q.push(right);
        } else {
            node->right = nullptr;
        }
    }

    return root;
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
     string res = serialize(root);
    cout << "Serialized: " << res << '\n';

    // deserialize
    cout << "Deserializing...\n";
    TreeNode* result = deserialize(res);

    // re-serialize the deserialized tree to verify correctness
    string res2 = serialize(result);
    cout << "Re-serialized after deserialization: " << res2 << '\n';

    // check round-trip equality
    cout << "Round-trip equal: " << (res == res2 ? "yes" : "no") << '\n';

}
//the time  complexity is O(n) and space complexity is O(N)

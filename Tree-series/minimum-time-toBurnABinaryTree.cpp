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
int findmaxi(map<TreeNode*,TreeNode*>&mpp,TreeNode*target){
    queue<TreeNode*>q;
    q.push(target);
    map<TreeNode*,int>vis;
    vis[target]=1;
    int maxi=0;
    while(!q.empty()){
       int sz=q.size();
       int fl=0;
       for(int i=0;i<sz;i++){
        TreeNode*curr=q.front();
        q.pop();
        if(curr->left && !vis[curr->left]){
            fl=1;
            vis[curr->left]=1;
            q.push(curr->left);
        }
        if(curr->right && !vis[curr->right]){
            fl=1;
            vis[curr->right]=1;
            q.push(curr->right);
        }
        if(mpp[curr] && !vis[mpp[curr]]){
            fl=1;
            vis[mpp[curr]]=1;
            q.push(mpp[curr]);
        }
       }
       if(fl)maxi++;

    }
    return maxi;
}
TreeNode* parents(TreeNode*root,map<TreeNode*,TreeNode*>&mpp,int start){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode*res;

    while(!q.empty()){
         TreeNode*curr=q.front();
         if(curr->data==start)res=curr;
         q.pop();
         if(curr->left){
            mpp[curr->left]=curr;
            q.push(curr->left);
         }
         if(curr->right){
            mpp[curr->right]=curr;
            q.push(curr->right);
         }

    }
    return res;

   

}
int minimumTime(TreeNode*root,int start){
     //queue<TreeNode*>q;
    map<TreeNode*,TreeNode*>mpp;
   TreeNode*target=parents(root,mpp,start);
   int maxi=findmaxi(mpp,target);
   return maxi;




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

    int ans=minimumTime(root,3);
    cout<<ans<<endl;

}

//here bfs is applicable because we have to traverse the node level wise
//the time comlexity is O(n)+O(n)+O(n) and space complexity is O(n)+O(n)




// #include <bits/stdc++.h>
// using namespace std;

// class TreeNode {
// public:
//     int data;
//     TreeNode *left, *right;
//     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// // Build parent pointers and return pointer to the node whose data == startVal
// TreeNode* buildParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int startVal) {
//     if (!root) return nullptr;
//     queue<TreeNode*> q;
//     q.push(root);
//     parent[root] = nullptr;
//     TreeNode* startNode = nullptr;
//     while (!q.empty()) {
//         TreeNode* curr = q.front(); q.pop();
//         if (curr->data == startVal) startNode = curr;
//         if (curr->left) {
//             parent[curr->left] = curr;
//             q.push(curr->left);
//         }
//         if (curr->right) {
//             parent[curr->right] = curr;
//             q.push(curr->right);
//         }
//     }
//     return startNode;
// }

// // BFS from target using parent/child edges. Return number of steps to burn entire tree.
// int timeToBurn(TreeNode* root, int startVal) {
//     if (!root) return 0;
//     unordered_map<TreeNode*, TreeNode*> parent;
//     TreeNode* target = buildParents(root, parent, startVal);
//     if (!target) return 0; // start value not found

//     queue<TreeNode*> q;
//     unordered_set<TreeNode*> vis;
//     q.push(target);
//     vis.insert(target);
//     int time = 0;

//     while (!q.empty()) {
//         int sz = q.size();
//         bool added = false;
//         for (int i = 0; i < sz; ++i) {
//             TreeNode* curr = q.front(); q.pop();
//             // left
//             if (curr->left && !vis.count(curr->left)) {
//                 vis.insert(curr->left);
//                 q.push(curr->left);
//                 added = true;
//             }
//             // right
//             if (curr->right && !vis.count(curr->right)) {
//                 vis.insert(curr->right);
//                 q.push(curr->right);
//                 added = true;
//             }
//             // parent
//             auto it = parent.find(curr);
//             if (it != parent.end() && it->second && !vis.count(it->second)) {
//                 vis.insert(it->second);
//                 q.push(it->second);
//                 added = true;
//             }
//         }
//         if (added) ++time;
//     }
//     return time;
// }

// int main() {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);
//     root->right->right->left = new TreeNode(8);

//     cout << timeToBurn(root, 3) << "\n"; // expected 3
//     return 0;
// }

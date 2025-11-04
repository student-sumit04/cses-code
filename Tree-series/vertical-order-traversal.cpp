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
vt<vt<int>> verticaltraversal(TreeNode*root){
    map<int,map<int,multiset<int>>>mpp;
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        TreeNode*node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        mpp[x][y].insert(node->data);
        if(node->left)q.push({node->left,{x-1,y+1}});
        if(node->right)q.push({node->right,{x+1,y+1}});


    }
    vt<vt<int>>vertical;
    for(auto it:mpp){
        vt<int>col;
        for(auto tem:it.second){
            col.insert(col.end(),tem.second.begin(),tem.second.end());
        }
        vertical.push_back(col);
    }
    return vertical;

}


signed main(){
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vt<vt<int>>ans=verticaltraversal(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j+1<ans[i].size())cout<<" ";
        }
        cout<<endl;
    }
   

}
//here we are using the level order traversal for traversing the tree along with map to store the values as follows like ({vertical,{level,multinodes}})
//the time complexity is O(n*logn) and O(2*n);
//queue is storing ({node,{vertical,level}});


//Topological sort is the linear ordering of the node such that if u->v then u appears before v in that ordering
//it is done in the directed acyclic graph
//this is done using the dfs -> topological sort
// the main intuition is that whose dfs is complete store them in the stack
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
void dfs(int node,vt<int>&vis,vt<vt<int>>&adj,stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
       
    }
     st.push(node);

}
vt<int>toposort(int v,vt<vt<int>>&adj){
    vt<int>vis(v,0);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    vt<int>ans;
    while(!st.empty()){
        ans.pb(st.top());
        st.pop();
    }
    return ans;

}
int main(){
    // the time complexity is O(v+e) and space complexity is O(2*n)
          
}
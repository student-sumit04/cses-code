// the defination of the scc is that we can visit each and every node in a component from any node of the component
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<int>temp;
stack<int>st;
vt<vt<int>>scc;
void dfs2(int node,vt<vt<int>>&adj,vt<int>&vis){
    vis[node]=1;
    temp.pb(node);
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs2(it,adj,vis);
        }
    }
}
void dfs(int node,vt<vt<int>>&adj,vt<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
    st.push(node);
}

void  solve(){
    int n,m;
    cin>>n>>m;
    vt<vt<int>>adj(n+1);
    vt<vt<int>>tadj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }
    vt<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,adj,vis);
        }
    }
    fill(vis.begin(),vis.end(),0);
    while(st.empty()==false){
        int node=st.top();
        st.pop();
        if(vis[node]==0){
             temp.clear();
            dfs2(node,tadj,vis);
            scc.push_back(temp);
           
        }
    }
    cout<<scc.size()<<endl;
    // for(auto &comp : scc){
    // for(auto node : comp){
    //     cout << node << " ";
    // }
    // cout << endl;
   //}
}
int main(){

}
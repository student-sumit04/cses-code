// this is the method of finding the cycle in the directed graph using dfs ;
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
bool dfs(int node,vt<vt<int>>&adj,vt<int>&vis,vt<int>&pathvis){
    vis[node]=1;//or vis[node]=2 if we don't want to use pathvis
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis))return true;//yes there exist a cycle
        }
        else if(pathvis[it])return true;//vis[it]==2
    }
    pathvis[node]=0;//vis[node]=1;
    return false;
}
bool iscyclic(int v ,vt<vt<int>>adj){
    vt<int>vis(v,0);
    vt<int>pathvis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis))return true;
        }
    }
    return false;

}
int main(){
    // the time complexity is O(V+E) and space complexity is O(2*v)
}
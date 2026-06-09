// here the cycle detection is done in the undirected graph using the bfs method
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
bool detect(int src,vt<vt<int>>&adj,vt<int>&vis){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(par!=it){
                return true;
            }
        }
    }
    return false;

}
bool isCycle(int  v,vt<vt<int>>&adj ){
    vt<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detect(i,adj,vis))return true;
        }
    }
    return false;
}
int main(){
    // the time complexity is O(n+2*e)+O(n)
    //space complexity is O(n);
}
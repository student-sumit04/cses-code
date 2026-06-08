#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;

bool dfs(int node,int col,vt<int>&color,vt<vt<int>>&adj){

    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
           if( dfs(it,!col,color,adj)==false)return false;
        }
        else if(color[it]==col)return false;
    }
    return true;


}
bool isBipartite(vt<vt<int>>&adj,int n){
    //the defination is that adjacent does need of same color then it is said to be bipartite
    int col=1;
    vt<int>color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
          if(dfs(i,col,color,adj)==false)return false;  
        }
    }
    return true;

}
int main(){
    //the time complexity will be (O(v+2*e));
    //even cycle lenght->bipartite graph
    // odd cycle lenght ->not a bipartite graph
   

}
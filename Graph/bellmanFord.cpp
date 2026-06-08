#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<int>bellmanford(int v,vt<vt<int>>&edges,int src){
    vt<int>dist(v,1e18);
    dist[src]=0;
    for(int i=0;i<v-1;i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e18 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    // the n th iteration
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e18 && dist[u]+wt<dist[v]){
            return {-1};
        }

    }
    return dist;

}


int main(){
    //the time complexity will be (O(v*e));
    //the no of iterations will be (n-1)times
    // if on the n th iterations if the dist vector gets updated it means negative weight cycle exists and it will handle it 
   
   

}
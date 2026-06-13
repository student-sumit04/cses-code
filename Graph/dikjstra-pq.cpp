// this is using the pq
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<int> dikjstra(int src,vt<vt<pair<ll,ll>>>&edges,int v,vt<int>&par){
    vt<int>dist(v,1e18);
    dist[src]=0;
//    vt<int>vis(v,0);
   priority_queue<pair<ll,ll>,vt<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

   pq.push({0,src});
  
   while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int node=it.second;
    int dis=it.first;
    for(auto ite:edges[node]){
        int wt=ite.second;
        int adjnode=ite.first;
        if(dis+wt<dist[adjnode]){
            dist[adjnode]=dis+wt;
            pq.push({dist[adjnode],adjnode});
            par[adjnode]=node;
           
        }
    }
   }
    return dist;
    

     
}
int main(){
    // the time complexity is O(ElogV);
    // it is somewhat is slower than using set 
    //it can not work with negative weight and negative weight cycle
}
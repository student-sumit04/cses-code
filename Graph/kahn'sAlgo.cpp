//
//it is done in the directed acyclic graph
//this is done using the bfs ->  Kahn's algorithm
// the main intuition is that whose insert all the nodes with indegree 0
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;

vt<int>toposort(int v,vt<vt<int>>&adj){
    
   vt<int>indegree(v,0);
   queue<int>q;
   for(int i=0;i<v;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
   }
   for(int i=0;i<v;i++){
    if(indegree[i]==0)q.push(i);
   }
   vt<int>topo;
   while(!q.empty()){
    auto node=q.front();
    q.pop();
    topo.pb(node);
    for(auto  it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0)q.push(it);
    }

   }
   return topo;

}
int main(){
    // the time complexity is O(v+e) and space complexity is O(2*n)
          
}
//the main intuition to check cycle detection using bfs is that we find out topo sort first then if topo.size()!=v then cycle exists

#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
bool isCycle(int v,vt<vt<int>>adj){
    vt<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)q.push(i);
    }
    vt<int>topo;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        topo.pb(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);

        }
    }
    if(topo.size()==v)return false;
    else return true;
}


int main(){
    // the time complexity is O(v+e) in worst case 
 
          
}
// this is using the set
#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<int> dikjstra(int src,vt<vt<pair<ll,ll>>>&edges,int v){
    vt<int>dist(v,1e18);
    dist[src]=0;
    set<pair<ll,ll>>st;
    vt<int>vis(v,0);
    st.insert({0,src});
    while(!st.empty()){
        pair<ll,ll>top=*st.begin();
        st.erase(top);
        int dis=top.first;
        int popnode=top.second;
       
        vis[popnode]=1;
        for(auto it:edges[popnode]){
            int adjnode=it.first;
            int wt=it.second;
            if(vis[adjnode]==1)continue;
            if(dist[adjnode]>dis+wt){
                if(dist[adjnode]!=1e18)st.erase({dist[adjnode],adjnode});
                dist[adjnode]=dis+wt;
                st.insert({dist[adjnode],adjnode});
            }


        }
    }
    return dist;
    

     
}
int main(){
    // the time complexity is O(ElogV);
    //using set is fastest 
}
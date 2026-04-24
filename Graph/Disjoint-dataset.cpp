#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;

class DisjointSet{
    vt<int>par,rsize,rank;
 public:
  DisjointSet(int n){
    par.resize(n+1);
    rank.resize(n+1,0);
    rsize.resize(n+1);
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    for(int i=0;i<=n;i++){
        rsize[i]=1;
    }
  }

    int findupar(int node){
        if(par[node]==node)return node;
        return par[node]=findupar(par[node]);
    }

    void unionByRank(int u,int v){
        int ulpu=findupar(u);
        int ulpv=findupar(v);
        if(ulpu==ulpv)return ;
        if(rank[ulpu]<rank[ulpv]){
            par[ulpu]=ulpv;

        }
        else if(rank[ulpu]>rank[ulpv]){
            par[ulpv]=ulpu;
        }
        else{
            par[ulpv]=ulpu;
            rank[ulpu]++;
        }
    }

    void unionBySize(int u,int v){
        int ulpu=findupar(u);
        int ulpv=findupar(v);
        if(ulpu==ulpv)return;
        if(rsize[ulpu]<rsize[ulpv]){
            par[ulpu]=ulpv;
            rsize[ulpv]+=rsize[ulpu];
        }

        else{
            par[ulpv]=ulpu;
            rsize[ulpu]+=rsize[ulpv];

        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findupar(3)==ds.findupar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"NOT Same"<<endl;
    }


}
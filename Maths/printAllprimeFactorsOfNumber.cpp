#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<int>fact(int num){
    vt<int>ans;
    for(int i=2;i*i<=num;i++){
        if(num%i==0)ans.pb(i);
        while(num%i==0)num=num/i;

    }
    if(num!=1)ans.pb(num);
    return ans;
}
int main(){
    int num;
    cin>>num;
    vt<int>primefactors=fact(num);
    for(auto it:primefactors){
        cout<<it<<" ";
    }
    cout<<endl;

}

//the time complexity of the function is O(sqrt(n)*log n) because everytime the num is getting divided and thus goes in the logarthimic time
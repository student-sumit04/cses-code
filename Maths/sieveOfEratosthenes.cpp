#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<int>check(ll n){
    vt<int>isprime(10000000,1);
     if (n >= 0) isprime[0] = 0;
    if (n >= 1) isprime[1] = 0;
    for(int i=2;i<n;i++){
        if(isprime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=0;
            }
        }
    }
    return isprime;
}

int main(){
    int num;
    cin>>num;
    vt<int>primes=check(num);
    vt<int>temp;
   for(int i=2;i<=num;i++){
    if(primes[i]==1)temp.pb(i);
   }
   for(auto it:temp){
    cout<<it<<" ";
   }
   cout<<endl;
    

}

//this is a precomputation technique used to find the whether a number is prime or not in the efficient manner

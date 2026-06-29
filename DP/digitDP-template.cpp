#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
vt<ll>digits;
ll dp[20]/*[4]*/[2][2];
ll dfs(int pos,/*other states */int tight,int leadingzero){
    // if(pos==digits.size())return (cntnz<=3)?1:0;
    if(pos==digits.size()){
        //return  1 or 0 or sum etc
    }
    ll &res=dp[pos][tight][leadingzero];
    if(res!=-1)return res;
    res=0;
    int limit=tight?digits[pos]:9;
    for(int d=0;d<=limit;d++){
      
        int nexttight=tight && (d==limit);
        int nextleadingzero=leadingzero && (d==0);
        //compute other next stages
       // int nextcntnz=cntnz+((d==0 && nextleadingzero)?0:(d!=0));
      // if(leadingzero && d==0)nextcntnz=cntnz;

        res+=dfs(pos+1,nexttight,nextleadingzero);
    }
    return res;
}



ll counttox(ll num){
    if(num<0)return 0;
    digits.clear();
    if(num==0)digits.pb(0);
    while(num>0){
        digits.pb(num%10);
        num=num/10;
    }
    reverse(digits.begin(),digits.end());
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,1);

   

  

}





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
         ll a,b;
       cin>>a>>b;
      cout<<counttox(b)-counttox(a-1)<<endl;

    }
    //the time complexity is O(S*len*10);
    //this is the standard recursive memoised template of digit dp 
  
   
   


 
    






   
   
   
 
  

   

















    
   


 



  
    


 
  
       

   
    
}

#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;

//z algorithm defines max substring starting from index i which is also a prefix

vt<int>z_function(string s){
    int n=s.length();
    vt<int>z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<r){
            z[i]=min(r-i,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

int main(){
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    vt<int> z = z_function(s);
    cout << "Z-array: ";
    for(int value : z){
        cout << value << ' ';
    }
    cout << endl;

    return 0;
}
//the time complexity is O(n);

#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;
//the booth algo is to check  whether one string is the  cyclic rotation of other  string ,i can run the 

//booth algo on these string


string minimal_string(string s){
    int n=s.length();
    s+=s;
    int i=0,j=1,k=0;
    while(i<n && j<n && k<n){
        if(s[i+k]==s[j+k]){
            k++;
        }
        else if(s[i+k]>s[j+k]){
            i=i+k+1;
            if(i<=j){
                i=j+1;
                
            }
            k=0;
        }
        else {
            j=j+k+1;
            if(j<=i){
                j=i+1;
            }
            k=0;
        }
    }
    int pos=min(i,j);
    return s.substr(pos,n);
}

bool areRotations(string first, string second){
    if(first.length() != second.length()){
        return false;
    }

    return minimal_string(first) == minimal_string(second);
}

int main(){
    string first, second;

    cout << "Enter the first string: ";
    getline(cin, first);

    cout << "Enter the second string: ";
    getline(cin, second);

    cout << "Minimum rotation of first string: "
         << minimal_string(first) << endl;
    cout << "Minimum rotation of second string: "
         << minimal_string(second) << endl;

    if(areRotations(first, second)){
        cout << "The strings are cyclic rotations." << endl;
    }
    else{
        cout << "The strings are not cyclic rotations." << endl;
    }

    return 0;
}
//the time complexity is O(n);
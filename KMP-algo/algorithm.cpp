#include<bits/stdc++.h>
#include<map>
#include<set>
#define vt vector
#define pb push_back
#define ll long long
using namespace std;

//way to compute the lps array
vt<int>computelps(string pattern){
    int m=pattern.size();
    vt<int>lps(m,0);
    int len=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
void kmpsearch(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    vt<int>lps=computelps(pattern);
    int i=0;//index of the text
    int j=0;//index of the pattern
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found"<<endl;
            j=lps[j-1];//use lps to continue search
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }

    }

}//the time complexity is the O(n+m);
int main(){
    string text, pattern;
    
    cout << "Enter the text: ";
    getline(cin, text);
    
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    
    cout << "\nSearching for pattern \"" << pattern << "\" in text \"" << text << "\"" << endl;
    kmpsearch(text, pattern);
    
    return 0;
}
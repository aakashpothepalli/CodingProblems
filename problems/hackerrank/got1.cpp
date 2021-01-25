#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<endl
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;

string gameOfThrones(string s) {
    unordered_map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    bool isOne=true,ans=true;
    for(auto it :m){
        if(it.second%2 ==1 && !isOne){
            ans=false;
            break;
        }
        if(it.second%2 ==1 && isOne){
                isOne = false;
        }
    }
    return ans?"YES":"NO";


}

int main(){
    string s ;cin>>s;
    cout<<gameOfThrones(s);
}
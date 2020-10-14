#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
using namespace std;
typedef  pair<int, int> pi ;

string my2(int n, int k, int x, int y){
    int c = 10000;
    int i=x;
    unordered_map<int,bool> m;
    m[i] = true;
    while(c--){
        i = (i+k)%n;
        m[i] =true;
    }
    if(m[y]){
        return "YES";
    }
    else{
        return "NO";
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k,x,y;cin>>n>>k>>x>>y;
        string ans2 = my2(n,k,x,y);
        cout<<ans2<<endl;
    }
    
}
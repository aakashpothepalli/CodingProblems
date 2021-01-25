#include<bits/stdc++.h>
#define ll long long
#define ulli unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define in2d(ar,n,m) for(int i=0;i<n;i++)for(int i=0;i<m;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl;
#define swap(a,b)\
    int t = a; \
    a = b; \
    b = t;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
#define maxar(ar,n,mx) for(int i=0;i<n;i++)mx =max(mx,ar[i])
#define all(ar) ar.begin(),ar.end()
#define fori(i,a,b) for(ll i=a;i<b;++i)

using namespace std;
typedef  pair<int, int> pi ;
typedef pair<ll,ll> pl;
typedef vector<vector<int>> vvi;
const ll mod = 1e9 + 7;
// incomplete

int main(){
    int t;cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
       ll ar[m];
       in(ar,m);
       ll ng=0,p=0;
       fori(i,0,m){
           if(ar[i]<0)ng++;
           else p++;
       }

       cout<<ng*p<<endl;
    }
}
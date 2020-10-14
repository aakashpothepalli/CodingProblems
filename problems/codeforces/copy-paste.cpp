
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
unordered_map<ll,ll> m;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        int ar[n];
        in(ar,n);
        
        int ans= 0;
       
        sort(ar,ar+n);
        for(int i=1;i<n;i++){
            ans += (k-ar[i])/ar[0];
        }

        cout<<ans<<endl;
    }
}
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
// 100 points

int main(){
    int t;cin>>t;
    while(t--){
        ll n,k,p,x;cin>>n>>x>>p>>k;
        ll ar[n];
        in(ar,n);
        sort(ar,ar+n);
        int ans = 0;
        
        if(ar[p-1]==x){
            cout<<0<<endl;
            continue;
        }
        
        if(k==p){
            if(ar[p-1]>x){
                int ind = upper_bound(ar,ar+n,x)- ar;
                // cout<<ind<<endl;
                ans = p-ind;
            }
            else{
                int ind = lower_bound(ar,ar+n,x)-ar;
                // cout<<ind<<endl;
                ans = ind+1 - p;
            }
        }
        else if(k>p){
            if(ar[p-1]<x){
                ans=-1;
            }
            else{
                int ind = upper_bound(ar,ar+n,x)- ar;
                // cout<<ind<<endl;
                ans = p-ind;
            }
        }
        else if(k<p){
            if(ar[p-1]>x){
                ans=-1;
            }
            else{
                int ind = lower_bound(ar,ar+n,x)-ar;
                // cout<<ind<<endl;
                ans = ind+1 - p;
            }
        }
        cout<<ans<<endl;
    }
}
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

using namespace std;
typedef  pair<int, int> pi ;


int main(){
    ll n,h;cin>>n>>h;
    ll ar[n];
    in(ar,n);

    vector<ll> t;
    ll ans = 0;
    for(int i=0;i<n;i++){
        t.push_back(ar[i]);
        sort(t.rbegin(),t.rend());
        ll h1=0;
        bool flag = false;
        for(ll j=0;j<t.size();j++){
            if(!flag){
                h1 += t[j];
                flag =true;
            }
            else {
                flag =false;
            }
            if(h1<=h){
                ans = max(j+1,ans);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
//maximize count( max(ar[0],ar[1])+max(ar[3],ar[2]) <=h)
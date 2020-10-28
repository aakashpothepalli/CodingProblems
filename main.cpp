#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl; 
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

#define fori(i,a,b) for(ll i=a;i<b;++i)

using namespace std;
const ll MOD  = (ll)(1e9+7);
typedef  pair<int, int> pi ;



ll gcd(ll a, ll b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);

}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ar[n];
        in(ar,n);
        int gd = ar[0];
        for(int i =1;i<n;i++){
            gd = gcd (gd,ar[i]);
        }
        if(gd==1){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}
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

int main(){
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll ar1[n];in(ar1,n);
        ll ar2[m];in(ar2,m);
        sort(ar1,ar1+n);
        sort(ar2,ar2+m);
        ll sum1 = 0, sum2 = 0;
        fori(i,0,n)sum1+=ar1[i];
        fori(i,0,m)sum2+=ar2[i];

        if(sum1>sum2){
            cout<<0<<endl;

        }
        else{
            bool flag = true;
            for(int i  =0 , j = m-1;i<n && j>=0 ;j--,i++){
                sum1-=ar1[i];
                sum2-=ar2[j];
                sum1+=ar2[j];
                sum2+=ar1[i];
                if(sum1>sum2){
                    cout<<i+1<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<-1<<endl;
            }
            
        }
    }
}
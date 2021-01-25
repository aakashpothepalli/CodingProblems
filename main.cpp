#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i];
#define invec(ar,n)for(int i  =0 ; i<n;i++){int temp;cin>>temp;ar.push_back(temp);}
#define in2d(ar,n,m) for(int i=0;i<n;i++)for(int i=0;i<m;i++)cin>>ar[i]
#define out(ar,n)     for(int i=0;i<n;i++)     cout<<ar[i]<<" ";     cout<<endl;
#define swap(a,b)    int t = a;     a = b;     b = t;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
#define maxar(ar,n,mx) for(int i=0;i<n;i++)mx =max(mx,ar[i])
#define fori(i,a,b) for(ll i=a;i<b;++i)
#define all(ar) ar.begin(),ar.end()
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;
const ll mod = 1e9 + 7;


int main(){
    int t;cin>>t;
    while(t--){
        unordered_map<int,int> m;
        int n;cin>>n;
        int ar[n];
        in(ar,n);
        int mx = INT_MIN;
        fori(i,0,n){
            m[ar[i]]++;
            mx = max(mx,ar[i]);
        }

        int mex =0;
        fori(i,0,mx+2){
            if(!m[i]){
                mex = i;
                break;
            }
        }
        
    }
}
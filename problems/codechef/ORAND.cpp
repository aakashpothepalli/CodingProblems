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

int n,m;
int a[10000],b[10000];
unordered_map<int,int> vis;
void solve(int v){
        if(vis[v]){
            return; 
        }
        else{
            for(int i =0  ; i<n;i++){
                vis[v] = true;
                solve(v|a[i]);
            }
            for(int i =0  ; i<m;i++){
                vis[v] = true;
                solve(v&b[i]);
            }
        }
}
int main(){
    int t;cin>>t;
    while(t--){
       cin>>n>>m;
       in(a,n);
       in(b,m);
       solve(0);
       int ans = 0;
       for(auto it : vis){
           if(it.second)ans++;
        //    cout<<it.first<<" ";
       }
        vis.clear();
    //    cout<<endl<<ans<<"\n\n";
    cout<<ans<<endl;
    }
}
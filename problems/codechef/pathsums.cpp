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

int main(){
    int t;cin>>t;
    while(t--){
        int n ;cin>>n;
        vector<int> g[n+1];

        for(int  i = 0;i<n-1;i++){
            int a, b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int ans[n+1];

        int level[n+1];
        level[1]= 1;
        queue<int> q;
        q.push(1);
        unordered_map<int,int> vis;
        vis[1] = true;
        while(!q.empty()){
            int p  =q.front();
            q.pop();

            for(int i = 0;i<g[p].size();i++){
                if(!vis[g[p][i]]){
                    vis[g[p][i]] = true;
                    level[g[p][i]] = level[p]+1;
                    q.push(g[p][i]);
                }
            }
        }

        for(int i =1;i<=n;i++){
            if(level[i]%2==0){
                ans[i] = 2;
            }
            else ans[i] = 1;
        }
        fori(i,1,n+1){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
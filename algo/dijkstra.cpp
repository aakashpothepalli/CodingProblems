#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

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
#define pii pair<int,int>
#define fori(i,a,b) for(ll i=a;i<b;++i)
const ll mod = 1e9 + 7;
using namespace std;
struct comp{
	bool operator()(pii a, pii b){
		if (a.first != b.first)
			return a.first > b.first;
		return a.second < b.second;
	}	
};
// dijkstra multisource shortest path
int main(){

    int t;cin>>t;
    while(t--){
    
        int n, m;
        cin>>n>>m;
		vector<pii> g[n+1];
        ll dis[n+1];
	    bool vis[n+1];
		int par[n+1];

        int s;cin>>s;
        vector<int> sources;
        fori(i,0,s){
            int temp;cin>>temp;
            sources.push_back(temp);
        }
        fori(i ,0,m){
            int u, v, w;
            cin>>u>>v>>w;
            g[u].push_back({w, v});
			g[v].push_back({w, u});
        }


    	priority_queue<pii, vector<pii>,comp> Q;

        for(int i=1; i<=n; i++){
            dis[i] = INT_MAX, vis[i] = 0;
        
        }
        for(int el :sources){
            dis[el] = 0;
            Q.push({0, el});
        }

        while(!Q.empty()){
            pii cur = Q.top(); Q.pop();
            if (vis[cur.second]) continue;
            vis[cur.second] = 1;
            dis[cur.second] = cur.first;
            for(pii x: g[cur.second]){
                int to = x.second, w = x.first;
                Q.push({cur.first+w, to});
            }
        }

        fori(i,1,n+1){
            cout<<i<<" "<<dis[i]<<endl;
        }
    }
}
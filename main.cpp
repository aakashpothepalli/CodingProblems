#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define  in(ar,n) for(int i=0;i<(int)n;i++)cin>>ar[i];
#define out(ar,n)     for(ll i=0;i<(int)n;i++)     cout<<ar[i]<<" ";     cout<<endl;
#define for2d(n,m) for(int i=0;i<(int)n;i++)for(int j=0;j<(int)m;j++)
#define fori(i,a,b) for(ll i=a;i<(int)b;++i)
#define all(ar) ar.begin(),ar.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;

// ncr factorial mod combination 
long long mod = 1e9+7;

// ll solve(ll i){
//     cout<<i<<endl;
//     if (i<0 || i>=4001 || m[i] ){
//         return INT_MAX;
//     }
//     else if(i==x){
//         return 0;
//     }
//     else {
//         if(a==b){
//             return 1 + solve(i+a);
//         }
//         return min(2 + solve(i+a-b),1+solve(i+a)); 
//     }
// }


// dijkstra multisource shortest path
// n = no of vertices
// m = no of edges
// sources = starting node/nodes
/*  
    graph input
    fori(i ,0,m){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
*/

struct comp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }    
};

void   dijkstra(int n, map<ll,vector<pll>> g,vector<ll> sources,int dest){

    unordered_map<int,ll> dis,par;
    unordered_map<int,bool> vis;
    // bool vis[n+1];
    // int par[n+1];

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,comp> Q;

    for(int i=-10001; i<=10001; i++){
        dis[i] = INT_MAX, vis[i] = 0;
    
    }
    for(int el :sources){
        dis[el] = 0;
        Q.push({0, el});
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.top(); Q.pop();
        if(cur.second==dest){
            // cout<<cur.first<<endl;
            break;
        }
        if ( vis[cur.second] ) continue;
        vis[cur.second] = 1;
        // if(cur.second<0|| m[cur.second] )continue;
        dis[cur.second] = cur.first;
        for(pair<ll,ll> x: g[cur.second]){
            ll to = x.first, w = x.second;
            par[to]  = cur.first;
            // cout<<cur.second<<" "<<to<<" "<<endl;;
            Q.push({cur.first+w, to});
        }
    }
    // cout<<endl;
    // print distance from source
    int mn = INT_MAX,ind = 0;

    // int i = dest;
    // cout<<dest<<" ";
    // do{cout<<par[i]<<" ";
    //     i = par[i];
    // }
    // while(i!=0);
    if(dis[dest]>=INT_MAX){
        puts("-1");
    }
    else{
        cout<<dis[dest]<<endl;
    }
}


int main(){
    unordered_map<int,bool> m;

int a,b,x;
int n;
    cin>>n;
    int f = -1;
    fori(i,0,n){
        int t;cin>>t;
        if(f==-1)f = t; 
        m[t] = true;
    }

    cin>>a>>b>>x;
    if(a==b){
        puts("-1");
        return 0;
    }
    // if(x*4==f){
    //     puts("-1");
    //     return 0;
    // }
    int n1 = 10001;
    map<ll,vector<pll>> g;

    for(int i =-10001;i<=10001;i++){
        // cout<<i<<endl;
        if(!m[i+a]){
            g[i].push_back({i+a,1});
            // g[i+a].push_back({i,1});
        }
        if(!m[i+a-b] && !m[i+a] ){
            // if(i+a-b>0){
            g[i].push_back({i+a-b,2});
            // g[i+a-b].push_back({i,2});
            // }
        }
    }    
    // for(auto it : g){
    //     vector<pll> p = it.second;
    //     int i = it.first;
    //     cout<<i<<" "<<g[i][0].first<<" ";
    //     // if(g[i].size()>=2){
    //         cout<<g[i][1].first<<" ";
    //     // }
    //     cout<<endl;
    // }   
    // for(int i = -20 ; i<=20;i++){
    //     cout<<i<<" "<<g[i][0].first<<" ";
    //     if(g[i].size()>=2){
    //         cout<<g[i][1].first<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"fine";
    dijkstra(n1,g,{0},x);
}
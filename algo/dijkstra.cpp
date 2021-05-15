
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
int dijkstra(int n,int m, vector<pair<int,int>> g[],vector<int> sources){

    long long dis[n+1];
    bool vis[n+1];
    int par[n+1];

    priority_queue<pair<int,int>, vector<pair<int,int>>,comp> Q;

    for(int i=1; i<=n; i++){
        dis[i] = INT_MAX, vis[i] = 0;
    
    }
    for(int el :sources){
        dis[el] = 0;
        Q.push({0, el});
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.top(); Q.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = 1;
        dis[cur.second] = cur.first;
        for(pair<int,int> x: g[cur.second]){
            int to = x.second, w = x.first;
            Q.push({cur.first+w, to});
        }
    }
    //print distance from source
    // fori(i,1,n+1){
    //     cout<<i<<" "<<dis[i]<<endl;
    // }
}

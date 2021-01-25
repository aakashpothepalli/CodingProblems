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

using namespace std;
typedef  pair<int, int> pi ;
typedef pair<ll,ll> pl;
typedef vector<vector<int>> vvi;
const ll mod = 1e9 + 7;

// custom comparision function for dijkstra
struct compdij{
    bool operator()(pii a, pii b){
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }    
};

//convert 2d index to 1d
int t2o(int x , int nRows,int y){
    int index = x * nRows + y;
    return index;
}

// convert 1d index to 2d
pair<int,int> o2t(int index,int nRows){
    return {index/nRows,index%nRows};
}
struct edge{
    int a,b,w;
};

class graph{

    unordered_map<int,vector<int>> g; //adjacency list for undirected
    unordered_map<int,vector<pii>> gd; //adjacency list for directed graph
    int n,m; //no of rows and cols
    unordered_map<int,int> dist; // distance from the source vertices
    unordered_map<int,bool> vis; //check if the vertice is visited  
    vector<int> sources; // starting vertices
    queue<int> q; // for bfs
    stack<int> st;// for dfs
    priority_queue<pii, vector<pii>,compdij> Q; //for dijkstra
    edge arr[25000001];
    // union find algo
    ll par[100001];
    string choice;    // choice  = "bfs" / "dfs" / "dijk", adjacency list


public:

    // choice  = "bfs" / "dfs" / "dijk", adjacency list
    void setParams(int n1,int m1,string choice){
        n = n1;
        m = m1;
        this->choice = choice;
    }
    // choice  = "bfs" / "dfs" / "dijk" , takes care of multisources also
    void addSources(vector<int> s){
        sources = s;
        if(choice=="bfs"){
            for(int el:s){
                q.push(el);
                vis[el] = true;
            }
        }
        else if(choice=="dfs"){
            for(int el :s){
                st.push(el);
                vis[el] = true;
            }
        }   
        else if(choice =="dijk"){
            for(int i=1; i<=n; i++){
                dist[i] = INT_MAX, vis[i] = 0;
            }
            for(int el :sources){
                dist[el] = 0;
                Q.push({0, el});
            }
        }
        else{
            throw invalid_argument("choice  = \"bfs\" / \"dfs\" / \"dijk\"");
        }
    }
    
    vector<int> init1d(){
        // array of size n
        vector<int> ar(n);
        in(ar,n);

        fori(i,0,n){
            if(i-1>=0){
                g[i].push_back(i-1);
                g[i-1].push_back(i);
            }
            if(i+1<n){
                g[i].push_back(i+1);
                g[i+1].push_back(i);
            }
        }
        return ar;
    }

    //n = no. of rows, m = no. of cols, choice  = "bfs" / "dfs" / "dijk", adjacency list
    void initNormal(){
        fori(i,0,m){
            int a;int b;cin>>a>>b;
            if(choice =="bfs" || choice =="dfs" ){
                g[a].push_back(b);
                g[b].push_back(a);
            }
            else if(choice =="dijk"){
                int w;cin>>w;
                gd[a].push_back({w,b});
                gd[b].push_back({w,a});
            }
            else{
                throw invalid_argument("choice  = \"bfs\" / \"dfs\" / \"dijk\"");
            }
        }
    }
    void initDiagonal(){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0 && j-1>=0  ){
                    g[t2o(i,n,j)].push_back(t2o(i-1,n,j-1));
                }
                if(i+1<n && j-1>=0 ){
                    g[t2o(i,n,j)].push_back(t2o(i+1,n,j-1));
                }
                if(i+1<n && j+1<m ){
                    g[t2o(i,n,j)].push_back(t2o(i+1,n,j+1));
                }
                if(i-1>=0 &&j+1<m ){
                    g[t2o(i,n,j)].push_back(t2o(i-1,n,j+1));
                }
            }
        }
    }
    void initLRTB(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0 ){
                    g[t2o(i,n,j)].push_back(t2o(i-1,n,j));
                }
                if(i+1<n ){
                    g[t2o(i,n,j)].push_back(t2o(i+1,n,j));
                }
                if(j+1<m ){
                    g[t2o(i,n,j)].push_back(t2o(i,n,j+1));
                }
                if(j-1>=0 ){
                    g[t2o(i,n,j)].push_back(t2o(i,n,j-1));
                }
            }
        }
    }
    void bfs(){
        while(!q.empty()){
            int p =q.front();
            q.pop();
            for(int i=0;i<g[p].size();i++){
                int k =g[p][i];
                if(!vis[k]){
                    vis[k] = true;
                    dist[k] = dist[p]+1;
                    q.push(k);
                }
            }
        }
    }

    void dfs(){
        while(!st.empty()){
            int p =st.top();
            st.pop();
            for(long unsigned i=0;i<g[p].size();i++){
                int k =g[p][i];
                if(!vis[k]){
                    vis[k] = true;
                    dist[k] = dist[p]+1;
                    st.push(k);
                }
            }
        }
    }
    void dijkstra(){
        while(!Q.empty()){
            pii cur = Q.top(); Q.pop();
            if (vis[cur.second]) continue;
            vis[cur.second] = 1;
            dist[cur.second] = cur.first;
            for(pii x: gd[cur.second]){
                int to = x.second, w = x.first;
                Q.push({cur.first+w, to});
            }
        }
    }
    void printDistance(){
        fori(i,1,n+1){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
    void printDistance1d(){
        fori(i,0,n){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
    bool comp(edge a,edge b){
        // minimum spanning tree
        if(a.w <b.w){
            // change <  to > to get maximum spanning tree
            return true;
        }
        return false;
    }

    ll find (ll a){
        if(par[a]<0){
            return a;
        }
        return par[a] =find(par[a]);
    }

    void merge(ll a  , ll b){
        a = find(a);
        b = find(b);
        if(a ==b)return;
        else
        par[a] = b;
    }
    void minimumSpanningTree(){
        int count = 0;

        for(int i =0;i<n;i++){
                int a,b,w;cin>>a>>b>>w;
                arr[count].a = a;
                arr[count].b = b;
                arr[count].w = w;
                count++;
        }

        sort(arr,arr+count,comp);
        ll ans = 0;
        for(int i=0;i<count;i++){
            ll a =find(arr[i].a);
            ll b= find(arr[i].b);
            if(a!=b){
                //this will run n-1 times
                ans+=arr[i].w;
                merge(a,b);
            }

        }

    }
    
    int getConnectedComponents(){
        int cc=0;
        for(auto it: g){
        int el = it.first;
        if(!vis[el]){
            cc++;
            queue<int> q;
            q.push(el);
            vis[el] = true;
            while(!q.empty()){
                int p = q.front();
                q.pop();

                for(int i = 0;i<g[p].size();i++){
                    int temp  = g[p][i];
                    if(!vis[temp]){
                        vis[temp] =true;
                        q.push(temp);
                    }
                }
            }
        }
    }
    return cc;
    }


};
int main(){
    // int t;cin>>t;
    // while(t--){
        graph a;
        int n;cin>>n;
        a.setParams(8,8,"bfs");
        a.initDiagonal();
        a.bfs();
        a.printDistance();
    // }
}
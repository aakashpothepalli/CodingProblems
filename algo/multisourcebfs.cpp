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
using namespace std;
const ll MOD  = (ll)(1e9+7);
typedef  pair<int, int> pi ;


int t2o(int x , int rowSize,int y){
    int index = x * rowSize + y;
    return index;
}

pair<int,int> o2t(int index,int rowSize){
    return {index/rowSize,index%rowSize};
}
// multisource bfs
int main(){
    int t;cin>>t;
    while (t--){
        int n, m;
        cin>>n>>m;
        int ar[n][m];
        for(int i = 0; i<n;i++){
            string s;cin>>s;
            for(int j  =0 ;j<m;j++){
                ar[i][j] = s[j] - '0';
            }
        }

        vector<int> g[n*m];
        vector<int> sources;
        for2d(n,m){
                int ind = t2o(i,m,j);
            if(ar[i][j]==1){
                sources.push_back(ind);
            }
                if(i-1>=0){
                    g[ind].push_back(t2o(i-1,m,j));
                    g[t2o(i-1,m,j)].push_back(ind);
                }
                if(i+1<n){
                    g[ind].push_back(t2o(i+1,m,j));
                    g[t2o(i+1,m,j)].push_back(ind); 
                }
                if(j-1>=0){
                    g[ind].push_back(t2o(i,m,j-1));
                    g[t2o(i,m,j-1)].push_back(ind);
                }
                if(j+1<m){
                    g[ind].push_back(t2o(i,m,j+1));
                    g[t2o(i,m,j+1)].push_back(ind);
                }
        }

        unordered_map<int,bool> vis;
        unordered_map<int,int> dist;
        queue<int> q;

        for(int i = 0;i<sources.size();i++){
            vis[sources[i]] = true;
            dist[sources[i]] = 0;
            q.push(sources[i]);
        }

        while(!q.empty()){
            int p = q.front();
            q.pop();

            for(int i = 0;i< g[p].size();i++){
                if(!vis[g[p][i]]){
                    vis[g[p][i]] = true;
                    dist[g[p][i]] = dist[p] + 1;
                    q.push(g[p][i]);
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j = 0; j<m;j++){
                cout<< dist[t2o(i,m,j)]<<" ";
            }
            cout<<endl;
        }
    }


}
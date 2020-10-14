#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
using namespace std;
typedef  pair<int, int> pi ;

int tb[100010][2];
int t2o(int x , int rowSize,int y){
    int index = x * rowSize + y;
    return index;
}
// bfs

// 5
// 1 1 0 0 1
// 1 0 1 1 0
// 0 0 0 0 0
// 0 0 0 1 0
// 0 0 0 0 0

//o/p 3
int main(){
    int n;cin>>n;
    int ar[n][n];
    vector<int> g[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // int a,b;cin>>a>>b;
            cin>>ar[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar[i][j]==1){
                if(i-1>=0 && ar[i-1][j]==1){
                    g[t2o(i,n,j)].push_back(t2o(i-1,n,j));
                }
                if(j-1>=0 && ar[i][j-1]==1){
                    g[t2o(i,n,j)].push_back(t2o(i,n,j-1));
                }
                if(i+1<n && ar[i+1][j]==1){
                    g[t2o(i,n,j)].push_back(t2o(i+1,n,j));
                }
                if(j+1<n && ar[i][j+1]==1){
                    g[t2o(i,n,j)].push_back(t2o(i,n,j+1));
                }
            }
        }
    }

    int ans = 1;

    queue<int> q;
    unordered_map<int,int> vis;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int p =q.front();
        q.pop();
        for(int i=0;i<g[p].size();i++){
            int k =g[p][i];
            if(!vis[k]){
                vis[k] = true;
                ans++;
                q.push(k);
            }
        }
    }
    cout<<ans<<endl;
}
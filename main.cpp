#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<" "
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(ar,n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
using namespace std;


int t2o(int x , int rowSize,int y){
    int index = x * rowSize + y;
    return index;
}

pair<int,int> o2t(int index,int rowSize){
    return {index/rowSize,index%rowSize};
}

// bfs  
// greedy
void solve(){

    int n,m;cin>>n>>m;
    int ar[n][m];
    char ans[n][m];
    for2d(ar,n,m){
        cin>>ar[i][j];
    }
    
    for2d(ar,n,m){
        if(ar[i][j]==-1){
            ans[i][j]='B';
            continue;

        }
        int index = t2o(i,m,j);

        bool flag = false;
        
        queue<int> q;
        q.push(index);
        unordered_map<int,bool> vis,level;
        level[index]=0;

        cout<<i+1<<" "<<j+1<<" - ";
        while(!q.empty()){
            int p = q.front();
            q.pop();
            pair<int,int> twoD = o2t(p,m);

            if(!vis[p]){
                int dist = level[p];
                vis[p]=true;
                int x=twoD.first,y = twoD.second;
                cout<<x+1<<" "<<y+1<<" "<<dist<<" , ";

                if(ar[x][y]>=dist && ar[x][y]!=0){
                    flag =true;
                    break;
                }

                if(x+1<n && ar[x+1][y]!=-1 ){
                    level[t2o(x+1,m,y)]= level[p]+1;
                    q.push(t2o(x+1,m,y));
                }
                if(x-1>=0 && ar[x-1][y]!=-1  ){
                    level[t2o(x-1,m,y)]= level[p]+1;
                    q.push(t2o(x-1,m,y));
                }
                if(y+1<m && ar[x][y+1]!=-1 ){
                    level[t2o(x,m,y+1)]= level[p]+1;
                    q.push(t2o(x,m,y+1));
                }
                if(y-1>=0 && ar[x][y-1]!=-1 ){
                    level[t2o(x,m,y-1)]= level[p]+1;
                    q.push(t2o(x,m,y-1));
                }
                
            }
        }

        if(flag){
            ans[i][j] = 'Y';
        }
        else{
            ans[i][j]= 'N';
        }
        cout<<endl;
    }

     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cout<<ans[i][j]<<" ";
         }
         cout<<endl;
    }

}
int main(){
    int t ;cin>>t;
    while(t--){
        solve();
    }
}
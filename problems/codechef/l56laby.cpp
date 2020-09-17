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

using namespace std;
typedef  pair<int, int> pi ;


int t2o(int x , int rowSize,int y){
    int index = x * rowSize + y;
    return index;
}

pair<int,int> o2t(int index,int rowSize){
    return {index/rowSize,index%rowSize};
}

// bfs min heap second pair
struct myComp {
    constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
    const noexcept
    {
        return a.second < b.second;
    }
};

void solve1(){
    int n,m;cin>>n>>m;

    priority_queue<pi, vector<pi>, myComp> q;
//    priority_queue<pair<int,int>> q;
    int ar[n][m];
    char ans[n][m];
    for2d(n,m){
        cin>>ar[i][j];
    }


    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(ar[i][j]>0){
            q.push({ t2o(i,m,j) , ar[i][j] });
            ans[i][j]='Y';
        }
        else if(ar[i][j]<0){
            ans[i][j]='B';
        }
        else{
            ans[i][j]='N';
        }
    }
        unordered_map<int,bool> vis;

    while(!q.empty()){
        pair<int ,int > pr = q.top();
        int p = pr.first;
        pair<int,int> twoD = o2t(p,m);
        q.pop();

        if(!vis[p]){

            vis[p]=true;
            int x=twoD.first,y = twoD.second;
            // cout<<x+1<<" "<<y+1<<" "<<dist<<" , ";
            if(pr.second>=0){
                ans[x][y] = 'Y';
            }

            if(x+1<n && ar[x+1][y]!=-1 ){
                q.push({t2o(x+1,m,y),pr.second-1});
            }
            if(x-1>=0 && ar[x-1][y]!=-1  ){

                q.push({t2o(x-1,m,y),pr.second-1});
            }
            if(y+1<m && ar[x][y+1]!=-1 ){
                q.push({t2o(x,m,y+1),pr.second-1});
            }
            if(y-1>=0 && ar[x][y-1]!=-1 ){
                q.push({t2o(x,m,y-1),pr.second-1});
            }

        }
    }

for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cout<<ans[i][j];
         }
         cout<<endl;
    }

}
int main(){
   int t ;cin>>t;
   while(t--){
        solve1();
   }
}
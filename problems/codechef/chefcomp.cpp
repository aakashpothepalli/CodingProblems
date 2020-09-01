
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<" "
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
typedef  pair<int, int> pi ;

int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> g[n];
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        int p[n],a[n],f[n],ans[n];
        set(ans,n,-1);
        in(p,n);
        in(a,n);
        in(f,n);

        unordered_map<int,bool> dead;
        unordered_map<int,bool> eaten;
        for(int i=0;i<n;i++){
            int city = p[i]-1;
            queue<int> q;
            q.push(city);
            unordered_map<int,bool> visited;
            visited[city]=true;

            while(!q.empty()){
                int cc = q.front();
                q.pop();

                vector<int> &cities = g[cc];

                for(auto nc:cities){
                    if(!visited[nc] && !dead[nc]){
                        int consume = min(a[city],f[nc]);
                        f[nc]-=consume;
                        if(f[nc]==0 && !eaten[nc]){
                            eaten[nc]= true;
                            ans[nc]= i+1;
                        }
                        visited[nc]= true;
                        q.push(nc);
                    }
                }
            }
            f[city]-=min(a[city],f[city]);
            dead[city]=true;
            if(f[city]==0 && !eaten[city]){
                eaten[city]= true;
                ans[city]= i+1;
            }
            // vector<int> &ncity =g[city];

            // for(int nc:ncity){
            //     int consume = min(a[city],f[nc]);

            // }


        }
        out(ans,n);
        cout<<endl;
    }
    return 0;
}

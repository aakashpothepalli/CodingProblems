
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

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int ra[n];
        in(ra,n);
        int rac[n][m];
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               cin>>rac[i][j];
           }
        }
        int fr[n][m];

        for2d(n,m){
            ra[i]+=rac[i][j];
            fr[i][j] = ra[i];
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<fr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int rat[n][m],rak[n][m];
        memset(rat,0,sizeof(rat));
        memset(rak,0,sizeof(rak));

        for(int i=0;i<m;i++){
            
            vector<pair<int,int>> m;
            for(int j=0;j<n;j++){
                m.push_back({fr[j][i],j});
            }
            sort(m.rbegin(),m.rend());
            
            int count =1;
            rak[m[0].second][i] = 1;
            for(int j=1;j<n;j++){
                if(m[j].first == m[j-1].first){
                    rak[m[j].second][i] = count;
                }
                else{
                    count= j+1;
                    rak[m[j].second][i] = count;

                }
            }
        }
        int mrat[n],mrak[n];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<rak[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            int mx =INT_MAX,mxd=0;
            for(int j=0;j<m;j++){
               if(mx>rak[i][j]){
                   mx = rak[i][j];
                   mxd = j;
               }
            }
            mrak[i] =mxd;

        }
        // rat

        for(int i=0;i<n;i++){
            int mx =0,mxd=0;
            for(int j=0;j<m;j++){
               if(mx<fr[i][j]){
                   mx = fr[i][j];
                   mxd = j;
               }
            }
            mrat[i] =mxd;

        }
        // out(mrak,n);
        // cout<<endl;
        // out(mrat,n);

        int ans =0;
        for(int i=0;i<n;i++){
            if(mrat[i]!=mrak[i])ans++;
        }
    cout<<ans<<endl;
    }

}
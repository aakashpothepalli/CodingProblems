
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

int main(){
    int t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(t--){
        string s;cin>>s;
        int n = s.size();
        string p = "hello";
        int m = p.size();
        int tb[n+1][p.size()+1];

        memset(tb,-1,sizeof(tb));

        for(int i=0;i<=m;i++){
            tb[0][i] =0;
        }
        for(int i=0;i<=n;i++){
            tb[i][0] =0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]){
                    tb[i][j] = 1 + tb[i-1][j-1];
                }
                else{
                    tb[i][j] = max(tb[i-1][j],tb[i][j-1]);
                }
            }
        }

        if(tb[n][m]==m){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

        
       

        
    }

}
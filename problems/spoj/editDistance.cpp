
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
// lcs insert replace delete strings dp
int main(){
    int t;cin>>t;
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    while(t--){
        string s;cin>>s;
        string p;cin>>p;
        int n = s.size();
        int m = p.size();
        int tb[n+1][m+1];

        memset(tb,-1,sizeof(tb));

        for(int i=0;i<=m;i++){
            tb[0][i] =n;
        }
        for(int i=0;i<=n;i++){
            tb[i][0] =m;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
              if(i==0){
                tb[i][j] = j;
              }
              else if (j==0){
                tb[i][j] = i; 
              }
              else if(s[i-1]==p[j-1]){
                    tb[i][j] = tb[i-1][j-1];
                }
                else{
                    tb[i][j] = 1+ min(tb[i-1][j],min(tb[i][j-1] ,tb[i-1][j-1]) );
                }
            }
        }

        int lcslen = tb[n][m];
        n = n-lcslen;
        m =m - lcslen; 
        cout<< lcslen<<endl;

        
    }

}
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

// dp triangle path sum
int main(){
    int t;cin>>t;
    
    while(t--){
        ll n;cin>>n;
        ll ar[n][n];
        
        memset(ar,-1,sizeof(ar));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin>>ar[i][j];
            }
        }

        ll tb[n+1][n+1];

        memset(tb,0,sizeof(tb));
        tb[0][0] = ar[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                 if (j==0){
                    tb[i][j] =ar[i][j] + tb[i-1][j];
                }
                else if(j==i){
                    tb[i][j] = ar[i][j] + tb[i-1][j-1];
                }
                else{
                    tb[i][j] =ar[i][j] + max(tb[i-1][j],tb[i-1][j-1]) ;
                }
            }
        }

        ll mx = 0;
        for(int i=0;i<n;i++){
            mx = max(tb[n-1][i],mx);

        }
        cout<<mx<<endl;
        
        
        

    }

}
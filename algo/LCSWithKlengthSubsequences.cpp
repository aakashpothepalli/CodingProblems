
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

    while(t--){
        int k;cin>>k;
        string s,p;cin>>s>>p;
        int n  = s.size(),m =  p.size();

        int tb[n+1][m+1],count[n+1][m+1];

        memset(tb,0,sizeof(tb));
        memset(count,0,sizeof(count));

        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                tb[i][j]  = max(tb[i-1][j],tb[i][j-1]);
                if(s[i-1]==p[j-1]){
                    count[i][j] = 1 + count[i-1][j-1];
                }

                if(count[i][j]>=k){

                    for(int a = k;a<=count[i][j];a++){
                        tb[i][j]  = max(tb[i][j],tb[i-a][j-a] + a);
                    }
                }
            }
        }
        
	

        cout<<tb[n][m]<<endl;




    }

}

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

int tb[1001][1001];
int solve(int n,int m , int a, int b){
    if(n<=0){
        return 0;
    }
    else if(tb[n][m]!=-1){
        return tb[n][m];
    }
    else{
        int a1 = solve(n-1,m,a,b)+a;
        int a2= solve(n-m,m,a,b) +b;
        
        return  tb[n][m] = min(a1,a2);  
    }
}

int main(){
    int t=1;

    while(t--){
        int n,m,a,b;cin>>n>>m>>a>>b;
        memset(tb,-1,sizeof(tb));
        int ans = solve(n,m,a,b);
        cout<<ans<<endl;

    }

    
    
}

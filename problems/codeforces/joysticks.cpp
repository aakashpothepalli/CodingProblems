
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

// sub problems
// dp recursion
int tb[1001][1001];
int solve(int n,int m,int t){
    if(n <= 0 || m <=0){
        return t;
    }
    else if(tb[n][m]!=-1){
        return tb[n][m];
    }
    else{
        int a1 = solve(n+1,m-2,t+1);
        int a2 = solve(n-2,m+1,t+1);
        return tb[n][m]  =max(a2,a1);

    }
}

int main(){
    int t=1;
    
    while(t--){
        int n,m;cin>>n>>m; 
        memset(tb,-1,sizeof(tb)); 
        if(n==1 && m==1){
            cout<<0<<endl;
        }
        else{
        int ans = solve(n,m,0);
        cout<<ans<<endl;
        }

        
    }

}
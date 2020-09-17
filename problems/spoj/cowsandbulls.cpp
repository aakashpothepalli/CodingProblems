#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl; ;cout<<endl;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
typedef  pair<int, int> pi ;
int tb[5010][5010];
// dp difference subsequence
ll solve(ll cows[],ll bulls[],int m ,int n,int i,int j){
    if(j==n){
        return 0;
    }
    else if(i==m ){
        return INT_MAX;
    }
    else if(tb[i][j]!=-1){
        return tb[i][j];
    }
    else{
        ll a = solve(cows,bulls,m,n,i+1,j+1)+ abs(cows[i]- bulls[j]);
        ll b= solve(cows,bulls,m,n,i+1,j);
        return tb[i][j]  = min(a,b);
    }
}
int main(){
    ll n,m;cin>>n>>m;;
    // n<=m;
    ll cows[m],bulls[n];
    in(bulls,n);
    in(cows,m);
    if(n==m){
        ll sum = 0;
        for(int i =0;i<n;i++){
            sum += abs(bulls[i]-cows[i]);
        }
        cout<<sum<<endl;
        return 0;
    }

    memset(tb,-1,sizeof(tb));
    sort(cows,cows+m);
    sort(bulls,bulls+n);
    ll ans = solve(cows,bulls,m,n,0,0);

    cout<<ans<<endl;


}
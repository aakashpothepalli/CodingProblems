
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

int tb[2010][2010];
int solve(int ar[],int n,int l,int r,int c){
    if(l>r){
        return 0;
    }
    else if(tb[l][r]!=-1){
        return tb[l][r];
    }
    else{
        int ans1 = solve(ar,n,l+1,r,c+1)+ ar[l]*c;
        int ans2 = solve(ar,n,l,r-1,c+1)+ar[r]*c;
        return tb[l][r] =   max(ans1,ans2);
    }
}
int main(){
    int t=1;

    while(t--){
        int n;cin>>n;
        if(n==0)break;
        memset(tb,-1,sizeof(tb));
        int ar[n];
        in(ar,n);
        int ans = solve(ar,n,0,n-1,1);
        cout<<ans<<endl;
    }

}

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


int knapsack(int w[],int val[],int s,int n){

    int t[n+1][s+1];

    for(int i=0;i<=n;i++){
        t[i][0]=0;
    }
    
    for(int i=0;i<=s;i++){
        t[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for (int j=1;j<=s;j++){
            if(w[i-1]>j)
                t[i][j] = t[i-1][j];
            else{
                t[i][j]=max(val[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
            }
        }
    }

    // cout<<t[n][s]<<endl;
    // if(tb[n][s]!=-1){
    //     return tb[n][s];
    // }
    // if(w[n-1]> s){
    //     return tb[n][s] = knapsack(w,val,s,n-1);
    // }
    // else {
    //     return tb[n][s] = max(val[n-1]+knapsack(w,val,s-w[n-1],n-1),knapsack(w,val,s,n-1));
    // }
    return t[n][s];
}
int main()
{

    int s,n;cin>>s>>n;
    int w[n],val[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>val[i];
    }

    int ans = knapsack(w,val,s,n);

    cout<<ans<<endl;
    
  
    return 0;
}

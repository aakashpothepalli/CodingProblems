
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


int tb[1001][1001];

int chefwed(int ar[],int len,int K,int n ,int l){
    // int &tb = t;
    if(n==0){
        return 0;
    }
    else if(tb[n][l]!=-1){
        return tb[n][l];
    }
    else{
        int ans =INT_MAX;

        unordered_map<int,int> m;

        int p1=0;
        for(int k =1;k<=len-l;k++){
            if(m[ar[l+k-1]]==1){
                p1++;
            }
            m[ar[l+k-1]]++;
            if(m[ar[l+k-1]] >1){
                p1++;
            }
            ans = tb[n][l] =min(ans,K+p1+ chefwed(ar,len,K,len-l-k,l+k));
        }

    }
        return tb[n][l] ;
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){

        int n,K;cin>>n>>K;
        for2d(n+1,n+1)tb[i][j]=-1;       
        int ar[n];
        in(ar,n);
        int ans = chefwed(ar,n,K,n,0);

        cout<<ans<<endl;
    }

}
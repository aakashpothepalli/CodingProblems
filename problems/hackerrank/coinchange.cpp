
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

// coin change
// dp
int main(){
   int n,sum;cin>>sum>>n;
   long ar[n];

   in(ar,n);

   long long tb[n+1][sum+1];

    for(int i=0;i<=n;i++){
        tb[i][0]= 1; 
    }
    for(int i =1;i<=sum;i++){
        tb[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(ar[i-1]<=j){
                tb[i][j] = tb[i-1][j] + tb[i][j-ar[i-1]] ;
            }
            else{
                tb[i][j] = tb[i-1][j];
            }
        }
    }

    cout<<tb[n][sum]<<endl;

}
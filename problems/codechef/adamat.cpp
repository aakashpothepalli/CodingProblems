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

int main(){
    int t;
    cin>>t;

    while(t--){
        ll n;cin>>n;
        ll ar[n][n];
        for2d(n,n){
            cin>>ar[i][j];
        }

        int a1 =0,a2=0;
        int a[n];
        for(int i=0;i<n;i++){
            if(ar[0][i]!=i+1){
                a[i] = 1;
            }
            else{
                a[i] =0;
            }
        }
        // out(a,n);

        int c =n-1;
        int ans =0;
        while(c>0){
            for(int i=c;i>0;i--){
                    c--;
                if(a[i] == 1){
                    ans++;
                    a[i]=0;
                    break;
                }
            }
            for(int i=c;i>0;i--){
                if(a[i]==1){
                    a[i]=0;
                }
                else{
                    a[i]=1;
                }
            }
        }
        // cout<<endl;
        // out(a,n);
        cout<<ans<<endl;

    }

}
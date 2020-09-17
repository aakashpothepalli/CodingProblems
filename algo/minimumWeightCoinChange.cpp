#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]

#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl; 

#define out2d(ar,n,m)( {\
    for(int i=0;i<n;i++){ \
      for(int j=0;j<m;j++) \
        cout<<ar[i][j]<<" "; \
      cout<<endl;\
    }});
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
using namespace std;
typedef  pair<int, int> pi ;

// coin change dp weight
int main(){

    int t;cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll wtotal =  abs(b-a);
        int n;cin>>n;
        int ar[n],coins[n];
        for(int i=0;i<n;i++){
            cin>>coins[i]>>ar[i];
        }

        ll tb[n+1][wtotal+1];
        memset(tb,0, sizeof(tb));
        for(int i=0;i<=wtotal;i++){
            tb[0][i]= INT_MAX;
        }
        
        for(int i =1;i<=n;i++){
            for(int j=1;j<=wtotal;j++){
                if(ar[i-1] <= j ){   
                    tb[i][j] = min(tb[i-1][j],coins[i-1]+tb[i][j-ar[i-1]]);
                }
                else{    
                    tb[i][j] = tb[i-1][j];
                }
            }
        }
        
        vector<int> ans;
        // out2d(tb,n+1,wtotal+1);
        if(tb[n][wtotal]==INT_MAX){
            cout<<"This is impossible.";
        }
        else{
            cout<<"The minimum amount of money in the piggy-bank is "<<tb[n][wtotal]<<".";
        }
        cout<<endl;
    

       
    }

}
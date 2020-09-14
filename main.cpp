#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<" ";cout<<endl;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
typedef  pair<int, int> pi ;

int main(){
  int t;cin>>t;

  vector<ll> ar(1000002);
  ar[0] = 0;
  
  for(ll i=1;i<ar.size();i++){
    ll count = 0;
    ull n = i;

    while(n%2 == 0){
      count++;
      n= n>>1;
    }
    ar[i] = count +ar[i-1];
  }


  fact[0] = 0;


  // while(t--){
  //   int n;cin>>n;
  //   cout<<ar[n]<<endl;

  // }
  

}
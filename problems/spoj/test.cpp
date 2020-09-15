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
 vector<int> ar;
 while(true){
   int n;cin>>n;
    if(n==42){
      for(int i=0;i<ar.size();i++){
        cout<<ar[i]<<endl;
      }
      break;
    }
    else
    ar.push_back(n);
    
 }

}
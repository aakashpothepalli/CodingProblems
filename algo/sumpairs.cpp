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

vector<int> randAr(int seed,int size){
   srand(seed);
   vector<int> ar;
   for(int i=0;i<size;i++){
     int ran = rand()%size;
     ar.push_back(ran);
   }
   return ar;

}
// Chefina and Swaps
// random array

int main(){
  int t;cin>>t;
  while(t--){
   int n;cin>>n;
   int ar[n];
   in(ar,n);
    
    int mini = INT_MAX;
      unordered_map<int,int> m;
    int maxi = 0;
    for(int i=0;i<n;i++){
      mini = min(mini,ar[i]);
      maxi = max(maxi,ar[i]);
      m[ar[i]]++;
    }
    int ans =0;

    for(int s=mini+mini;s<=maxi+maxi;s++){
        int temp=0;       
        unordered_map<int,int> v;
        for(int i=0;i<n;i++){
          if(v[i]==1)
            continue;
          for(int j=i+1;j<n;j++){
            
            if(ar[i]+ar[j]==s && v[j]!=1){
              temp++;
              v[i]=1;
              v[j]=1;
              break;
            }
          }
        }
        // cout<<temp<<endl;
        ans = max(temp,ans);      
    }

    cout<<ans<<endl;

  }
  return 0;
}

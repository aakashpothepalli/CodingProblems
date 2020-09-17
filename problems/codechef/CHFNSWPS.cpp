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
    ll a1[n],a2[n];
    in(a1,n);
    in(a2,n);
    int xr=0;
    ll mini =INT_MAX;
    for(int i=0;i<n;i++){
      xr^=a1[i]^a2[i];
      mini = min(mini,min(a1[i],a2[i]));
    }
    if(xr){
      cout<<-1<<endl;
      continue;
    }

    // vector<int> a1,a2;
    // int seed =time(0)%n;
    // // seed = 4;
    // cout<<"seed "<<seed<<"\n";
    // a1 = randAr(seed,n);
    // a2 = randAr(seed,n);
    
    // for(int i=0;i<n;i++){
    //   int temp = a1[i];
    //   int rIndx = rand()%n;
    //   a1[i] = a2[rIndx];
    //   a2[rIndx]= temp;
    // }

    // sort(a1.begin(),a1.end());
    // sort(a2.begin(),a2.end());    
    // out(a1,n);
    // cout<<endl;
    // out(a2,n);
    // cout<<endl;


    map<ll,ll> m1,m2;
    for(int i=0;i<n;i++){
      m1[a1[i]]++;
      m2[a2[i]]++;

    }
 
    for(auto it: m1){

      ll mi = min(it.second,m2[it.first]);
      m1[it.first] -= mi;
      m2[it.first] -= mi;

    }
    

    for(auto it: m2){
      ll mi = min(it.second,m1[it.first]);
       m1[it.first] -= mi;
      m2[it.first] -=mi;
    }

    
    vector<ll> an1,an2;
    for(auto it:m1){  
      
      for(int i=0;i<it.second/2;i++){
        an1.push_back(it.first);
      }
    }
   

    for(auto it:m2){
     
      for(int i=0;i<it.second/2;i++){
        an2.push_back(it.first);
      }
    }
   
    // cout<<endl;
    // out(an1,an1.size());
    // cout<<endl;
    // out(an2,an2.size());
    // cout<<endl;

    ll ans =0;

    int a=0,b=0;

    reverse(an2.begin(),an2.end());
    for(int i=0;i<an1.size();i++){
      ans += min(mini*2,min(an1[i],an2[i]));
    }
    cout<<ans<<endl;
  }
  return 0;
}

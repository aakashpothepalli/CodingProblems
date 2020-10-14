// 20 points
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
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
using namespace std;
typedef  pair<int, int> pi ;

// vector<pi> ansr;
// map<pi,ll> m;
ll solve(ll a , ll b,ll c, ll d,int count){
    
    if (a==c && b==d){
        // v.push_back({a,b});
        // for(int i=0;i<v.size();i++){
        //     cout<<a<<" "<<b<<" , ";
        // }
        // cout<<endl;
        return 0;
    }
    // else if(m[{a,b}]!=0){
    //     return m[{a,b}];
    // }
    else if( count>8){
        return INT_MAX;
    }
    else{
        // v.push_back({a,b});
        // cout<<a<<" "<<b<<endl;
        ll east = 1+ solve(a+2*b,b,c,d,count+1);
        ll west = 1 +solve(a-2*b,b,c,d,count+1);
        ll north,south;

        if(b+2*a >= 0){
            north = 1+ solve(a,b+2*a,c,d,count+1);
        }
        else{
            north = 1+ solve( a*(-1) , (b+2*a)* (-1) ,c,d,count+1);

        }
        if(b-2*a >= 0){
            south = 1 +solve(a,b-2*a,c,d,count+1);
        }
        else{
            south = 1+ solve( a*(-1) , (b-2*a)* (-1) ,c,d,count+1);
        }
        
        return min(min(north,south),min(east,west));
       
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        ll a,b,c,d;cin>>a>>b>>c>>d;

        // for(int i=0;i<100;i++)ansr.push_back({1,1});

        ll ans = solve(a,b,c,d,0);

        // for(int i=0;i<ansr.size();i++){
        //     cout<<a<<" "<<b<<" , ";
        // }
        cout<<ans<<endl;
    }
}
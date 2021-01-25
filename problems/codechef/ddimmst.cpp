#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define in2d(ar,n,m) for(int i=0;i<n;i++)for(int i=0;i<m;i++)cin>>ar[i]
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
typedef pair<ll,ll> pl;

// 10/100 points
// maximum spanning tree
// union find
struct edge{
    int a,b,w;
};
bool comp(edge a,edge b){
    if(a.w >b.w){
        return true;
    }
    return false;
}
ll par[5001];
edge arr[25000001];

ll find (ll a){
    if(par[a]<0){
        return a;
    }
    return par[a] =find(par[a]);
}

void merge(ll a  , ll b){
    a = find(a);
    b = find(b);
    if(a ==b)return;
    else
    par[a] = b;
}
int main(){
    ll n;cin>>n;
    ll d;cin>>d;
    int ar[n][d];
    memset(par,-1,sizeof(par));


    for2d(n,d)cin>>ar[i][j];

    int count = 0;

    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
                ll difsum =0;

            for(int k=0;k<d;k++){
                difsum += abs(ar[i][k]- ar[j][k]);

            }
            arr[count].a = i;
            arr[count].b = j;
            arr[count].w = difsum;
            count++;
        }
    }

    sort(arr,arr+count,comp);
    ll ans = 0;
    for(int i=0;i<count;i++){
        ll a =find(arr[i].a);
        ll b= find(arr[i].b);
        if(a!=b){
            ans+=arr[i].w;
            merge(a,b);
        }

    }
    cout<<ans<<endl;

}

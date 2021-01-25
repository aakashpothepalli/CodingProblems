#include<bits/stdc++.h>
#define ll long long
#define ulli unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)scanf("%d",&ar[i]);
#define in2d(ar,n,m) for(int i=0;i<n;i++)for(int i=0;i<m;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl;
#define swap(a,b)\
    int t = a; \
    a = b; \
    b = t;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
#define maxar(ar,n,mx) for(int i=0;i<n;i++)mx =max(mx,ar[i])
#define all(ar) ar.begin(),ar.end()
#define fori(i,a,b) for(ll i=a;i<b;++i)

using namespace std;
typedef  pair<int, int> pi ;
typedef pair<ll,ll> pl;
typedef vector<vector<int>> vvi;
const ll mod = 1e9 + 7;

int n,k;
int ar[4001];
int tb[8002][4001];
int suf[4002];
int solve(int i ,int c){
    if(c<0){
        if(i>=k && suf[c+1]-i>=k) return 0;
        else return 9000;
    }
    else if(i >=k && suf[c+1] - i>=k){
        return 0;
    }
    else if(tb[i][c]!=-1)return tb[i][c];
    else{
        if(i>=k){
            return tb[i][c] = 1+solve(i,c-1);
        }
        else if(i+ar[c]>=k){
            return  tb[i][c]= 1 + solve(i+ar[c],c-1);
        }
        return tb[i][c] = 1 + min(solve(i+ar[c],c-1),solve(i,c-1));
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        memset(tb,-1,sizeof(tb));
        in(ar,n);
        sort(ar,ar+n);
        memset(suf,0,sizeof(suf));

        suf[n] = 0;
        ll s1 = 0;
        int count  =0 ;
        for(int i = 0  ; i<n;i++){
            s1+=ar[i];
            ar[i]  = min(ar[i],4001);
        }

       
        for(int i = n-1;i>=0;i--){
            suf[i] = suf[i+1] + ar[i];
        }

        int ans = solve(0,n-1);

        if(ans>=9000){
            cout<<-1<<endl;
        }
        else 
        cout<<ans<<endl;
    }
}
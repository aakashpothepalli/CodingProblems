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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pi> ar;

    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        ar.push_back({temp,i});
    }

    sort(ar.rbegin(),ar.rend());
    ll ans = 0;

    vector<int> indexes;

    for(int i=0;i<m*k;i++){
        ans+=ar[i].first;
        indexes.push_back(ar[i].second);    
    }
    sort(indexes.begin(),indexes.end());

    cout<<ans<<endl;
    for(int i=0;i<k-1;i++){
        cout<<indexes[(i+1)*m-1]+1<<" ";
    }

    return 0;
}
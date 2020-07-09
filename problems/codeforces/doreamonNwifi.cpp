#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<endl
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;

ll fact(int n){
    ll fac = 1;
    for(int i=1;i<=n;i++){
        fac*=i;
    }
    return fac;
}
int main(){
    string s;cin>>s;

    int n= s.size();

    unordered_map<char,int> m,m1;
    vector<int> pl,mi;
    for(int i=0;i<n;i++){
        m[s[i]]++;
        
    }

    string e;cin>>e;

    for(int i=0;i<n;i++){
        m1[e[i]]++;
    }

    if(m1['+']>m['+'] || m1['-']>m['-']){
        print(0);
        return 0;
    }

    for(int i=0;i<n;i++){
        if(e[i]!='?'){
            m[e[i]]--;
        }
    }
    
    int mis =m1['?'];
    int plus = m['+'];
    int minus = m['-'];

    ll num = fact(mis)/(fact(plus) * fact(minus));
    ll denom = pow(2,mis);

    double ans = (double)num/denom;

    // print(ans);
    cout<<setprecision(9)<<ans<<endl;
}
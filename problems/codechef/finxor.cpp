#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl; ;cout<<endl;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
typedef  pair<int, int> pi ;

int solve(){

    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        
        ll k = 1048576 ; // 2 power 20
        cout<<"1 "<<k<<endl;
        ll sum;
        cin>>sum;
        sum = sum - (n*k);
        
        vector<int> ans; //stores binary numbers
        for(ll i=19;i>0;i--){
            k = 1<<i;
            cout<<"1 "<<k<<"\n"<<flush;
            ll xort;
             cin>>xort;

            if(xort==-1){
                return 0;
            }
            ll sumt = sum + n*k ;
           
            ll a = abs(sumt-xort)/2;

            // formula XOR(a,b) = SUM(a,b) - 2*AND(a,b) ;
            a/=k;

            if(a%2==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }
        }

        ans.push_back(0);

        ll finalAns = 0;

        for(int j=0;j<ans.size();j++){
            finalAns = (finalAns<<1) + ans[j];
        }

        //edge case
        if(sum%2==1){
            finalAns++;
        }

        cout<<finalAns<<"\n"<<flush;
        int incorrect;

        cin>>incorrect;
        if(incorrect==-1){
            return 0;
        }
        
    }
    return 0;
}

int main(){
        
        solve();
    
}
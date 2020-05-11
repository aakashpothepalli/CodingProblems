#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;


int noOfFactors(int n){
    ll ans = 0;

    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){
                ans++;
            }
            else{
                ans+=2;
            }
        }
    }

    return ans%1000000007;
}
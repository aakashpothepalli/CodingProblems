#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;


ll gcd(ll a, ll b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);

}
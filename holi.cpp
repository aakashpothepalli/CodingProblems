#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i];
#define invec(ar,n)for(int i  =0 ; i<n;i++){int temp;cin>>temp;ar.push_back(temp);}
#define in2d(ar,n,m) for(int i=0;i<n;i++)for(int i=0;i<m;i++)cin>>ar[i]
#define out(ar,n)     for(int i=0;i<n;i++)     cout<<ar[i]<<" ";     cout<<endl;
#define swap(a,b)    int t = a;     a = b;     b = t;
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
#define maxar(ar,n,mx) for(int i=0;i<n;i++)mx =max(mx,ar[i])
#define fori(i,a,b) for(ll i=a;i<b;++i)
#define all(ar) ar.begin(),ar.end()
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;


// ncr factorial mod combination 
long long mod = 1e9+7;

//add sub mul div mod 10^9+7
// long long mod = 1e9+7;
long long  addMOD(long long a , long long b){
    return (a%mod + b%mod)%mod;
}

long long subMOD(long long a, long long b){
    return (((a%mod - b%mod) % mod + mod) % mod);
}

long long mulMOD(long long a , long long b){
    return ((a%mod)* (b%mod))%mod;
}

  long long gcdExtended(long long a, long long b, long long *x, long long *y) { 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    long long x1, y1;
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
   
long long modInverse(long long b, long long m) 
{ 
    long long x, y; 
    long long g = gcdExtended(b, m, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 
  
long long divMOD(long long a, long long b) 
{ 
    a = a % mod; 
    long long inv = modInverse(b, mod); 
    if (inv == -1) {
       cout << "Division not defined"; 
       return -1;
    }
    else{
        return (inv*a)%mod;
    }
}
long long power(long long x, long long y, long long p)  {  
    long long res = 1; 
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)  {  
        if (y%2 == 1)  
            res = (res*x) % p;  
         y/=2; 
        x = (x*x) % p;  
    }  
    return res;  
} 

long long fact[100000];
void factmod(long long n , long long p ){
    fact[0] =1 ;
    for(long long i= 1;i<=n;i++){
        fact[i] = ((fact[i-1]%p)*(i%p))%p;
    }
}

long long ncr(long long n, long long r){
    return ( fact[n]%mod * power(fact[n-r],mod -2,mod)%mod * power(fact[r],mod-2,mod)%mod )%mod;
}

ll n;
int main(){
    int t;cin>>t;
    factmod(31000,mod);
    while(t--){
        cin>>n;

        ll ans = 1;
        ll temp ;
        for(int i= 1;i<=n/2;i++){
            ll select = ncr(n,i*2);
            ll pairsways = divMOD(fact[i*2],mulMOD(fact[i],power(2,i,mod)));
            ans = (ans+ mulMOD(select,pairsways))%mod; 
        }

        cout<<ans<<endl;

    }

}
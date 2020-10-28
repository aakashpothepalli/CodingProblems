// fac factorial mod algo

int power(ll x, ll y, ll p)  {  
    int res = 1; 
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)  {  
        if (y%2 == 1)  
            res = (res*x) % p;  
        y = y/=2; 
        x = (x*x) % p;  
    }  
    return res;  
} 

ll fact[100000];
void factmod(int n , int p ){
    fact[0] =1 ;
    for(ll i= 1;i<=n;i++){
        fact[i] = ((fact[i-1]%p)*(i%p))%p;
    }
}

ll C(ll n, ll r){
    return ( fact[n]%mod * power(fact[n-r],mod -2,mod)%mod * power(fact[r],mod-2,mod)%mod )%mod;
}

// ncr combination 
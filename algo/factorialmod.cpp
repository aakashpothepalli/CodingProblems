// ncr factorial mod 
long long mod = 1e9+7;
int power(long long x, long long y, long long p)  {  
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

// ncr combination 

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
// mod power algo
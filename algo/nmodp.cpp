ll largePower(unsigned ll x, unsigned int y, int p)  
{  
    ll r= 1;
    x = x % p; 
    if (x == 0) return 0;
  
    while (y > 0)  {  
        if (y & 1)  
            r = (r*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return r;  
}
long long largePower(unsigned long long x, unsigned int y, int p)  
{  
    long long r= 1;
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
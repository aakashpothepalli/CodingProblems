//add sub mul div mod 10^9+7
long long mod = 1e9+7;
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


bool isPrime(ll n){
    if(n==1)return 1;
    for(ll i  = 2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true ;
}
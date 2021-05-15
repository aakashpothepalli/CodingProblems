bool isPrime(long long  n){
    if(n==1)return 1;
    for(long long i  = 2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true ;
}
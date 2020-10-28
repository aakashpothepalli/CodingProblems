void findDivisors(ll n ){
    ll ans = n;
    // m stores the powers of prime factors
     unordered_map<ll,ll> m ;
     while(n%2==0){
         n/=2;
         m[2]++;
        //  cout<<"by 2"<<endl;
     }
     for(ll i = 3;i<=sqrt(n);i+=2){
         while(n%i==0){
             n/=i;
             m[i]++;
            //  cout<<"by "<<i<<endl;
         }
     }
     if(n>2)m[n]++;

     // no of factors can be found out by multiplying 
     // product of all i in map - it(i).second+1
}
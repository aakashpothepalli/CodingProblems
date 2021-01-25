

vector<int> primes;
void sieve(int n){
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++){

        if (prime[p] == true) {
            primes.push_back(p);
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
}
 
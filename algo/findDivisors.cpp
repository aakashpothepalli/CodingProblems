set<ll> s ;
void findDivisors(ll n){ 
	for (int i=1; i<=sqrt(n); i++){ 
		if (n%i == 0){ 
			if (n/i == i) {
				s.insert(i);
            }

			else {
				s.insert(i);
                s.insert(n/i);
            }
		} 
	} 
} 

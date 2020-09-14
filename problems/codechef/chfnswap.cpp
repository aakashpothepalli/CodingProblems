#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<" "
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
typedef  pair<int, int> pi ;

ull solve1(ull n){
   if(n==1 ||n==2 ){
            return 0;

    }
    else if(n==3){
        return 2;
    }
    else {
        ull sum = n*(n+1)/2;
        if(sum%2==0){
            long double xin = (sqrt(1 + 4*sum));

            ull ans =floor(( xin - 1)/2.0);

            ull n2 = n*n;
            ull ans2 = ans*ans;
            ull nans = n-ans;
            if((ans2+ans) == sum){
                // cout<<endl<<"YES"<<endl;
                return ( (nans*nans )+ ans2 - (ans<<1) +n )>>1;
            }

            return ( n-ans);
            }
            else {
                return 0;
            }
        }
           
    
        //x2 + x - sum = 0
        // x2 = (-1 + sqrt(1 + 4* n))/2
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ull n;
        scanf("%llu",&n);
        ull a1 = solve1(n);
        printf("%llu\n",a1);
           
    }
}


 
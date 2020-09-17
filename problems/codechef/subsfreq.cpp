
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl; 
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)

using namespace std;
typedef  pair<int, int> pi ;

vector<int> randAr(int seed,int size){
    //  srand(seed);
    vector<int> ar;
    for(int i=0;i<size;i++){
        int ran = rand()%size;
        ar.push_back(ran);
    }
    return ar;

}


pair<string,pair<string,string>> genRandom(int n)
{
    string a;
    string alp ="abcdefghijklmnopqrstuvwxyz";

    for(int i=0;i<n;i++)
        a.push_back(alp[rand() % alp.size()]);

    // cout<<a<<endl;
    string ans = a;
    sort(a.begin(),a.end());

    int i = rand()%a.size();
    int j = rand()%a.size();
    if(i==j)
        j = rand()%a.size();
    int len = abs(i-j);
    string b = a.substr(i ,len);
    // cout<<i<<" "<<j<<endl<<b<<endl;

    return {ans,{b,a}} ;
}

int calc(int nos,int k,int p){
    return nos*k+p;
}
int calp(map<int,int> m){
    int p =0;

    for(auto it:m){
        if(it.second>1){
            p+=it.second;
        }
    }
    return p;
}
void printmap(map<int,int> m){
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
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

int main(){
    // srand(time(0));
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ar[n];
        in(ar,n);
        unsigned ll one =1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[ar[i]]++;
        }
        
        for( int i=n-1;i>=0;i--){
          cout<< largePower(2,i,1000000007)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
 
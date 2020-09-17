#include<bits/stdc++.h>
#define ll long long int
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
ll tb[12][102][2];

// digit dp
ll getSum(vector<int>  ar,int n,int pos , ll sum,bool isRestricted){
    if(n<pos){
        return sum;
    }
    else if(tb[pos][sum][isRestricted]!=-1){
        return tb[pos][sum][isRestricted];
    }
    else{
        ll res = 0;
        int limit = 9;
        if(isRestricted){
            limit = ar[pos-1];
        }
        
        for(int i=0;i<=limit;i++){
            if( i < limit || !isRestricted ){
                res += getSum(ar,n,pos+1,sum+i,false);
            }
            else
                res += getSum(ar,n,pos+1,sum+i,true);
        }
        
        return tb[pos][sum][isRestricted] = res;
    }
}
int main(){

    while(true){
        string  s,p;cin>>s>>p;
        if(s=="-1" && p=="-1"){
            break;
        }
        vector<int> ar1,ar2;
        
        for(int i=0;i<p.size();i++){
            ar1.push_back(p[i]-'0');
        }
        for(int i=0;i<s.size();i++){
            ar2.push_back(s[i]-'0');
        }

        memset(tb,-1,sizeof(tb));
        ll ans1  = getSum(ar1,ar1.size(),1,0,true);
        memset(tb,-1,sizeof(tb));
        ll ans2 = getSum(ar2,ar2.size(),1,0,true);
        
        int digitSum = 0;

        for(int i =0;i<ar2.size();i++){
            digitSum+=ar2[i];
        }
        cout<<ans1 - ans2 + digitSum<<endl;

    }
}
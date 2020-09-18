#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]

#define out(ar,n) \
    for(int i=0;i<n;i++) \
    cout<<ar[i]<<" "; \
    cout<<endl; 

#define out2d(ar,n,m)( {\
    for(int i=0;i<n;i++){ \
      for(int j=0;j<m;j++) \
        cout<<ar[i][j]<<" "; \
      cout<<endl;\
    }})
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define for2d(n,m) for(int i=0;i<n;i++)for(int j=0;j<m;j++)
using namespace std;
typedef  pair<int, int> pi ;

// matrix chain multiplication mcm operations addition multiplication 

/*
 * 1
 * 5*3+2*6
*/
ll tbmx[100][100],tbmn[100][100];
ll solveMin(vector<int> ar,vector<char> oper , int i ,int j){
    if(i==j){
        return ar[i];
    }
    else if(tbmn[i][j]!=-1){
        return tbmn[i][j];
    }
    else{
        ll ans = INT64_MAX;
        for(int k=i;k<j;k++){
            ll pref = solveMin(ar,oper,i,k);

            ll suff = solveMin(ar,oper,k+1,j);
            
            char op = oper[k];

            if(op=='+'){
                ans = min(ans,pref+suff);
            }
            else{
                ans = min(ans,pref*suff);
            }
        }
        return tbmn[i][j] = ans;
    }
}
ll solveMax(vector<int> ar,vector<char> oper , int i ,int j){
    if(i==j){
        return ar[i];
    }
    else if(tbmx[i][j]!=-1){
        return tbmx[i][j];
    }
    else{
        ll ans = 0;
        for(int k=i;k<j;k++){
            ll pref = solveMax(ar,oper,i,k);

            ll suff = solveMax(ar,oper,k+1,j);
            
            char op = oper[k];

            if(op=='+'){
                ans = max(ans,pref+suff);
            }
            else{
                ans = max(ans,pref*suff);
            }
        }
        return tbmx[i][j] =ans;
    }
}
int main(){

    int t;cin>>t;
    while(t--){
        memset(tbmn,-1,sizeof(tbmn));
        memset(tbmx,-1,sizeof(tbmx));
        string s ;cin>>s;
        int n = s.size();
        vector<int> ar;
        vector<char> oper;
        for(int i =0;i<n;i++){
            if(isdigit(s[i])){
                ar.push_back(s[i]-'0');
            }
            else{
                oper.push_back(s[i]);
            }
        }
        ll minAns = solveMin(ar,oper,0,ar.size()-1);
        ll maxAns = solveMax(ar,oper,0,ar.size()-1);

        cout<<maxAns<<" "<<minAns <<endl;
       
    }

}
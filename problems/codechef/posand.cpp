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
#define minar(ar,n,mn) for(int i=0;i<n;i++)mn =min(mn,ar[i])
#define MOD (ll)1000000007
using namespace std;
typedef  pair<int, int> pi ;

int tb[100010][2];
int count  =0;
vector<int> ans;
// permutations 
int solve(int n,int count,unordered_map<int,int> vis,vector<int> ar){
    if(count==n){
        ans = ar;
        return 1;
    }
    else{
        for(int i=1;i<=n;i++){
            if(count==0 || ( !vis[i] && (ar.back()&i)!=0 )){
                vis[i] = true;
                ar.push_back(i);
                int a = solve(n,count+1,vis,ar);
                if(a==1){
                    return 1;
                }
                ar.pop_back();
                vis[i] = false;
            }
        }
    }
    return 0;
}
  

vector<int> my1(int n){

    if(log2(n)==floor(log2(n))){
        return {-1};
    }
    vector<int> ar={1,3,2,6,4,5,7,9,8,10};
    
    for(int i=10;i<n;i++){
        ar.push_back(i+1);
    }
    for(int i=10;i<n-1;i++){
        if(log2(ar[i]) == floor(log2(ar[i]))){
            int temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
            i++;
        }
    }
    vector<int> ans;

    for(int i=0;i<n;i++){
        ans.push_back(ar[i]);
    }
    return ans;

}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(log2(n)==floor(log2(n))){
            cout<<-1<<endl;
            continue;
        }
        if(n<10){
            solve(n,0,{},{});
            out(ans,ans.size());
            ans.clear();
        }
        else{
            vector<int> ar1 = my1(n);
            out(ar1,ar1.size());
        }
    }
}
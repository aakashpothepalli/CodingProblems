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
using namespace std;
typedef  pair<int, int> pi ;

int tb[100010][2];
int t2o(int x , int rowSize,int y){
    int index = x * rowSize + y;
    return index;
}

int main(){
    int d;cin>>d;
    string z ;cin>>z;

    string ans = "";

    for(int i=0;i<d;i++){
        if(z[i]!='0' && z[i]!='1'){
            if(z[i]=='8'){
                ans+= "7222";
            }
            else if(z[i]=='9'){
                ans+="7332";
            }
            else if(z[i]=='4'){
                ans+="322";
            }
            else if(z[i]=='6'){
                ans+="53";
            }
            else{
                ans.push_back(z[i]);
            }
        }
    }
        sort(ans.rbegin(),ans.rend());
        cout<<ans<<endl;
}
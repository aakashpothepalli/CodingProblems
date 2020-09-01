
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

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ar[n];
        in(ar,n);
        int c =0;
        vector<int> v;
        int zeros=0;
        for(int i=0;i<n;i++){
            if(ar[i]==0 ){
                c++;
            }   
            else{
                if(c!=0)
               v.push_back(c);
                c=0;
            }
        }
        int mx =0,mx1 =0;
        unordered_map<int,int> m1;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
                mx= max(mx,v[i]);

                m1[v[i]]++;
        }

        if(mx%2==1  ){
            if(v.size()>=2 && v[0]/2 + 1 <= v[1])
                cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }

}
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
using namespace std;


int main(){
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        vector<int> ar;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            ar.push_back(temp);
        }
        map<int,vector<int>> m;
        for(int i =0;i<ar.size();i++){
            m[ar[i]].push_back(i);
        }
        pair<int,int> mxp ={0,0};
// no adjacent pairs 

// no consecutive
        for(auto it:m){
            vector<int> a = it.second;
            int count=0;

        //    cout<<it.first<<" - ";
            // out(a,a.size());
            for(int i=0;i<a.size();i++){
                if(i==a.size()-1){
                    count++;
                    break;
                }

                if(a[i]+1==a[i+1]){
                    i++;
                }
                count++;
            }
            // cout<<count<<" ";
            if(mxp.second <count){
                mxp.second = count;
                mxp.first = it.first;
            }
             count=0;
            for(int i=1;i<a.size();i++){
                if(i==a.size()-1){
                    count++;
                    break;
                }
                if(a[i]+1==a[i+1]){
                    i++;
                }
                count++;
            }
                        // cout<<count<<" "<<endl;

            if(mxp.second <count){
                mxp.second = count;
                mxp.first = it.first;
            }
        }
        cout<<mxp.first<<endl;

    }
    
}
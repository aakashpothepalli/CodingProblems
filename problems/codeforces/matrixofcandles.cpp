#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<" "
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;

vector<int> convertS2Ar(string* s,int n){
    vector<int> list;
    
    for(int i=0;i<n;i++){
        string s1 = s[i];
        int indG=0,indS=0;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='G')
                indG =j;
            else if(s1[j]=='S')
                indS = j;
        }
        list.push_back(indS-indG);
    }

    return list;
}
int main(){
    int n,m;cin>>n>>m;
    string s[n];

    for(int j=0;j<n;j++)
        cin>>s[j];
    
    vector<int> ar  = convertS2Ar(s,n);
        int mi = INT_MAX;

    for(int i=0;i<ar.size();i++){
        if(ar[i]<0){
            cout<<-1<<endl;
            return 0;
        }
        mi = min(mi,ar[i]);

    }
    bool flag = true;
    int ans =0;
    while(flag){
        flag = false;
        for(int i=0;i<ar.size();i++){
            ar[i]-=mi;
            
        }
        ans++;
        mi = INT_MAX;
        for(int i=0;i<ar.size();i++){
            if(ar[i]>0){
                mi = min(mi,ar[i]);
                flag = true;
            }
        }
        //                             cout<<mi<<endl;

        // out(ar,ar.size());

        // cout<<endl;
        

    }

    cout<<ans<<endl;


}
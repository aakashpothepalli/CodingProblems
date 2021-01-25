#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<endl
#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define invec(ar,n) for(int i=0;i<n;i++){int temp;cin>>temp;ar.push_back(temp);}
#define countmap(m,arr) for(int i=0;i<arr.size();i++) m[arr[i]]++
using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    unordered_map<int,int> am,bm;
    countmap(am,arr);
    countmap(bm,brr);
    vector<int> ans;
    for(auto it : bm){  
        if(it.second > am[it.first])
        ans.push_back(it.first);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> arr,brr;
    invec(arr,n);
    int m;cin>>m;
    invec(brr,m);
    vector<int> ans =missingNumbers(arr,brr);
    out(ans,ans.size());
}
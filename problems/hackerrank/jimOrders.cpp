#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<endl
#define outspace(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<" "

#define print(val) cout<<val<<endl;
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
#define invec(ar,n) for(int i=0;i<n;i++){int temp;cin>>temp;ar.push_back(temp);}
#define countmap(m,arr) for(int i=0;i<arr.size();i++) m[arr[i]]++
using namespace std;

vector<int> jimOrders(vector<pair<int,int>> orders) {
    vector<int> ans ;
    sort(orders.begin(),orders.end());
    for(int i=0;i<orders.size();i++){
        ans.push_back(orders[i].second);
    }
    return ans;

}


int main(){
    int n;cin>>n;
    vector<pair<int,int>> ar;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        ar.push_back({a+b,i+1});
    }
    vector<int> ans = jimOrders(ar);
    outspace(ans,n);
}
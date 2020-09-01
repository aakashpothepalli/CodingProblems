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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;cin>>n;
    vector<int> ar ;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        ar.push_back(t);
    }
    int time =144;
    
    int mx=ar[0];
    long beer=0;
    
    int maxarl[n];
    for(int i=0;i<n;i++){
        maxarl[i] = max(mx,maxarl[i]);
    }

    int maxarr[n];
    int mxr = ar[n-1];
    for(int i=n-1;i>=0;i--){
        maxarr[i] = max(mxr,maxarr[i]);
    }

    for(int i=0;i<n;i++){
         int maxl = maxarl[i];
        int maxr = maxarr[i];
        // for(int j=i;j<n;j++){
        //     if(maxr<ar[j]){
        //         maxr = ar[j];
                
        //     }
        // }
        // for(int j=i;j>=0;j--){
        //     if(maxl<ar[j]){
        //         maxl= ar[j];
        //     }
        // }
        
        int lower = min(maxr,maxl);
        
        beer += lower - ar[i] ;
        
        
    }
    cout<<beer*time<<endl;
    return 0;
}
//6
// 5 3 7 2 4 5

//864
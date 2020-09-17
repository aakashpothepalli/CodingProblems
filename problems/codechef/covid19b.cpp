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

using namespace std;
typedef  pair<int, int> pi ;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;cin>>n;
        int ar[n];in(ar,n);
        double pos[n];
        int inf[n];
        int mn = INT_MAX,mx =0;

        for(int k=0;k<n;k++){
            memset(inf,0,sizeof(inf));
            inf[k] = 1;
            for(double t=0;t<=50;t++){
                for(int i=0;i<n;i++){
                    pos[i] = i*10 + ar[i]*t;
                }


                for(int i =0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i!=j && pos[i] >=pos[j]
                        && (pos[i]-ar[i] < pos[j]-ar[j])
                        && (inf[i]==1 || inf[j]==1)){
                            inf[j] = 1;
                            inf[i] = 1;

                        }
                    }
                }
            }
            int ans = 0;
            for(int i=0;i<n;i++){
                // cout<<inf[i]<<" ";
                if(inf[i]==1){
                    ans++;
                }
            }
                mn= min(mn,ans);
                mx =max(mx,ans);
            // cout<<endl;
        }
        cout<<mn<<" "<<mx<<endl;


    }

}


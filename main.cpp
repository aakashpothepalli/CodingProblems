#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;



int testbit(ull x, ull y , ull l, ull r){
       unsigned ll mx = 0;
       unsigned ll z=0;

       for(unsigned ll i=l;i<=r;i++){
           if(mx < (x&i)*(y&i)){
//               cout<<mx<<"- mx "<<i<<endl;
               mx = (x&i)*(y&i);
               z = i;
           }
       }
       cout<<z<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        ull x,y,l,r;cin>>x>>y>>l>>r;
        
        // cout<<endl;
        // testbit(x,y,l,r);
        if(x==0 || y==0){
            cout<<0<<endl;
            continue;
        }
        ull z=0;
        int i=50;

        while(i>=0){
           
            if((r>>i)&1 ==1 ){
                i--;
                break;
            }else{
               
            }
            i--;
        }
        while(i>=0){
             if(((x>>i)&1)==1 || ((y>>i)&1)==1){
                ull temp = (z|(1<<i)); // case 2
                if(temp<=r){
                    z = temp;
                }
            }
        }
   
        ull mx =0;

/*

    3 cases
    z is greater than r
    z is in between l and r
    z is  less than l
*/
        cout<<z<<endl;
    }
}



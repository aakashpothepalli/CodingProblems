
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

vector<int> randAr(int seed,int size){
  //  srand(seed);
   vector<int> ar;
   for(int i=0;i<size;i++){
     int ran = rand()%size;
     ar.push_back(ran);
   }
   return ar;

}


pair<string,pair<string,string>> genRandom(int n) 
{
    string a;
string alp ="abcdefghijklmnopqrstuvwxyz";

    for(int i=0;i<n;i++)
    a.push_back(alp[rand() % alp.size()]);

    // cout<<a<<endl;
    string ans = a;
    sort(a.begin(),a.end());

    int i = rand()%a.size();
    int j = rand()%a.size();
    if(i==j)
      j = rand()%a.size();
    int len = abs(i-j); 
    string b = a.substr(i ,len);
    // cout<<i<<" "<<j<<endl<<b<<endl;

    return {ans,{b,a}} ;
}

int main(){
      // srand(time(0)); 
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;cin>>t;
  while(t--){
  unordered_map<char,int> m;
  string s ,p;
  cin>>s>>p;

  for(int i=0;i<s.size();i++){
    m[s[i]]++;
  } 
  for(int i=0;i<p.size();i++){
    m[p[i]]--;
  }

  string s1="";
  for(auto it:m){
    for(int i=0;i<it.second;i++)
    s1.push_back(it.first);
  }

  sort(s1.begin(),s1.end());
  int g1 = upper_bound(s1.begin(),s1.end(),p[0]) - s1.begin();
  int g2 = lower_bound(s1.begin(),s1.end(),p[0]) - s1.begin();

  string ans1="",ans2="";

  ans1.append(s1.substr(0,g1));
  ans1.append(p);
  ans1.append(s1.substr(g1,s1.size()-g1));

 ans2.append(s1.substr(0,g2));
  ans2.append(p);
  ans2.append(s1.substr(g2,s1.size()-g2));

if(ans1<ans2)
  cout<<ans1<<endl;
else
{
  cout<<ans2<<endl;
}

  }
  return 0;
}

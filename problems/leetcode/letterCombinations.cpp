#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define out(ar,n) for(int i=0;i<n;i++)cout<<ar[i]<<endl
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;


vector<string> ans;
void solve(string s,string digits,int i){
    if(i==digits.size()){
        if(s!="")
        ans.push_back(s);
        return;
    }
    else{
        if(digits[i]=='2'){
            solve(s+"a",digits,i+1);
            solve(s+"b",digits,i+1);
            solve(s+"c",digits,i+1);
        }
        else if(digits[i]=='3'){
            solve(s+"d",digits,i+1);
            solve(s+"e",digits,i+1);
            solve(s+"f",digits,i+1);

        }
        else if(digits[i]=='4'){
            solve(s+"g",digits,i+1);
            solve(s+"h",digits,i+1);
            solve(s+"i",digits,i+1);
     
        }
        else if(digits[i]=='5'){
            solve(s+"j",digits,i+1);
            solve(s+"k",digits,i+1);
            solve(s+"l",digits,i+1);
            
        }
        else if(digits[i]=='6'){
            solve(s+"m",digits,i+1);
            solve(s+"n",digits,i+1);
            solve(s+"o",digits,i+1);

        }
        else if(digits[i]=='7'){
            solve(s+"p",digits,i+1);
            solve(s+"q",digits,i+1);
            solve(s+"r",digits,i+1);
            solve(s+"s",digits,i+1);

        }
        else if(digits[i]=='8'){
            solve(s+"t",digits,i+1);
            solve(s+"u",digits,i+1);
            solve(s+"v",digits,i+1);

        }
        else if(digits[i]=='9'){
            solve(s+"w",digits,i+1);
            solve(s+"x",digits,i+1);
            solve(s+"y",digits,i+1);
            solve(s+"z",digits,i+1);

        }
    }
}
vector<string> letterCombinations(string digits) {
    solve("",digits,0);

    return ans;
}

int main(){
    string s;cin>>s;
    vector<string> a= letterCombinations(s);

    out(a,a.size());
}

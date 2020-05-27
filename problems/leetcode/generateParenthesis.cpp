#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;


unordered_map<int,set<string>> dp;

void filldp(int n){
    
    dp[1].insert("()");
    for(int i=2;i<=n;i++){

        for(auto s:dp[i-1]){
            dp[i].insert("("+s+")");

        }

       for(auto s:dp[i]){
            
            for(int j=1;j<s.size()-2;j++){
                if(s[j]=='(' && s[j+1]==')'){
                    string s1 =s;
                    s1[j]=')';
                    s1[j+1]='(';
                    // cout<<s1<<endl;
                    bool canInsert =true;
                    int sum=0;
                    for(char c :s1){
                        if(c =='('){
                            sum++;
                        }
                        else{
                            sum--;
                        }

                        if(sum<0){
                            canInsert = false;
                            break;
                        }
                    }
                    if(canInsert)
                        dp[i].insert(s1);
                }   
            }
        }
        for(auto s:dp[i-1]){
            dp[i].insert("()"+s);
            dp[i].insert(s+"()");
        }

    }
   
}

vector<string> generateParenthesis(int n) {
    filldp(n);

    vector<string> ans ;
    for(auto it : dp[n]){
        ans.push_back(it);
    }
    return ans;
}


vector<string> editAns;

void editorialSolution(int n,int l,int r,string s){
    if(n==0){
        editAns.push_back(s);
        return;
    }
    else {
        if(l!=0)
        editorialSolution(n-1,l-1,r,s+"(");
        if(r!=0 && r-1>=l)
        editorialSolution(n-1,l,r-1,s+")");

    }
}



int main(){
    int n;cin>>n;

    vector<string> ans = generateParenthesis(n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    cout<<ans.size()<<endl;

    // editorialSolution(2*n-1,n-1,n,"(");

    // for(int i=0;i<editAns.size();i++){
    //     cout<<editAns[i]<<endl;
    // }
    // cout<<editAns.size()<<endl;
}

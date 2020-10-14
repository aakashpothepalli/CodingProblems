// took me 7 months!! IDK why!!!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;

string longestPalindrome(string s) {
    
    string ans ="";
    int n = s.size();
    for(int i=0;i<n;i++){
        string temp="";
        int x,y;
        x=y=i;

        while( x>=0 && y<n && s[x]==s[y]){
            if(ans.size()<y-x+1){
                ans = s.substr(x,y-x+1);
            }
            x--;y++;
        }

    }
    for(int i=0;i<n-1;i++){
        string temp="";
        int x,y;
        x=i;
        y=i+1;
 
        while( x>=0 && y<n && s[x]==s[y]){
            if(ans.size()<y-x+1){
                ans = s.substr(x,y-x+1);
            }
            x--;y++;
        }

    }

    return ans;
}

int main(){
    string s;cin>>s;
    cout<<longestPalindrome(s);
}
//daomdukomcayjwgmmetypncdeixarhbectjcwftjjtwjrctixtrsehegwlfotpljeeqhntacfihecdjysgfmxxbjfeskvvfqdoedfxriujnoeteleftsjgdsagqvcgcdjbxgmguunhbjxyajutohgbdwqtjghdftpvidkbftqbpeahxbfyamonazvubzirhqseetaneptnpjbtrtitttxsyjckjvwtrmuwgidkofvobrwrffzrpnxbectsydbvswstfiqranjzhsebjnmprjoirqkgttahrivkcjtitdcpohwwerwgrdivqbltfnigavydxpmitttjjzyrmpaptkczzgnsovebvxezkkovgqegctxacvjfqwtiycnhartzczcgosiquhmdbljjzyrnmffcwnkyzytnsvyzayrieqyrfpxintbbiyrawxlguzaisedwabpzvevlejadztuclcpwvonehkhknicdksdcnjfaoeaqhcdkdtywilwewadcnaprcasccdcnvdgjdqirrsqwzhqqorlhbgpelpupdvuynzybcqkffnnpocidkkigimsa
//tjjt ans
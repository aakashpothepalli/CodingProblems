//not efficient
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        
        vector<int> temp;
        unordered_map<int,int> m1;
        
        for(int i =0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        for(auto it:m1){
            for(int i =0;i<it.second && i<3;i++){
                temp.push_back(it.first);
            }
        }

        nums = temp;        
        unordered_map<int,int> m;
        set < vector<int> > amap;
        for(int i=0;i<nums.size();i++){
            
            m[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++)for(int j=i+1;j<nums.size()-1;j++){

            if(m.count(-nums[i] -nums[j])==1 &&  m[-nums[i] -nums[j]]>j ){
                vector<int> t;
                t.push_back(nums[i]);
                t.push_back(nums[j]);
                t.push_back(-nums[j]-nums[i]);
                sort(t.begin(),t.end());
                amap.insert(t);
            }
        }
        for(auto el:amap){
            ans.push_back(el);
        }
        return ans;
    }
};
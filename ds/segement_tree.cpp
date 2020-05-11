#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

#define  in(ar,n) for(int i=0;i<n;i++)cin>>ar[i]
#define set(ar,n,val) for(int i=0;i<n;i++)ar[i]=val
using namespace std;

class segmentTree{
private:
    int* tree,*ar;
    int n;

    void buildtree(int start, int end, int treeNode){

        if(start==end){

                this->tree[treeNode] =ar[start];

            return;
        }
        int mid = (start+end)/2;

        this->buildtree(start,mid,2*treeNode);
        this->buildtree(mid+1,end,2*treeNode+1);

        this->tree[treeNode] = this->tree[2*treeNode] + this->tree[2*treeNode+1];
    }

    void updateTreeUtil(int i,int j ,int value,int node,int index){

        if(i==j){
            this->tree[node] =value;
            return;
        }
        else{

            int mid = (i+j)/2;
            if(i<=index && index<=mid){
                updateTreeUtil(i,mid,value,2*node,index);
            }
            else if(mid+1<=index && j>=index){
                updateTreeUtil(mid+1,j,value,2*node+1,index);
            }
            this->tree[node] = this->tree[2*node] + this->tree[2*node+1];

        }

    }
    int getSumUtil(int i,int j, int l,int r,int node){

        if(i>=l && j<=r){
            return this->tree[node];
        }
        else if(j < l || i > r ){
            return 0;
        }
        else{
            int mid = (i+j)/2;
            int sum1 = getSumUtil(i,mid,l,r,2*node);
            int sum2 = getSumUtil(mid+1,j,l,r,2*node+1);
            return sum1+sum2;
        }

    }

public:
     segmentTree(const int arr[],int n){
        this->tree = new int[2*n];
        this->ar = new int[n+1];
        this->n = n;

        for(int i=1;i<=n;i++){
            this->ar[i]= arr[i-1];
        }

        buildtree(1,n,1);
    }


    int getSum(int l,int r){

        return getSumUtil(1,this->n,l,r,1);
    }

    void updateTree(int index,int value){
        updateTreeUtil(1,this->n,value,1,index);
    }
    void printTree(){
        for(int i=1;i<2*n;i++){
            cout<<tree[i]<<'\n';
        }
    }

};

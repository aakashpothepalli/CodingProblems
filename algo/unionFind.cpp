struct edge{
    int a,b,w;
};
edge arr[25000001];
// union find algo
bool comp(edge a,edge b){
    // maximum spanning tree
    if(a.w >b.w){
        // change >  to < to get minimum spanning tree
        return true;
    }
    return false;
}
ll par[100001];

ll find (ll a){
    if(par[a]<0){
        return a;
    }
    return par[a] =find(par[a]);
}

void merge(ll a  , ll b){
    a = find(a);
    b = find(b);
    if(a ==b)return;
    else
    par[a] = b;
}


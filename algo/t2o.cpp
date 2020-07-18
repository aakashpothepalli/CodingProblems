#include <bits/stdc++.h>
using namespace std;

int t2o(int x , int rowSize,int y){
    int index = x * rowSize + y;
    return index;
}

pair<int,int> o2t(int index,int rowSize){
    return {index/rowSize,index%rowSize};
}
#include <bits/stdc++.h>
using namespace std;
// random array generator
vector<int> randAr(int seed,int size){
   srand(seed);
   vector<int> ar;
   for(int i=0;i<size;i++){
     int ran = rand()%size;
     ar.push_back(ran);
   }
   return ar;

}
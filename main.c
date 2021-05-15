#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 20
#define x 4+1

int main(){
   int a  =5;
   int b = ++a * a++;
   printf("%d",b);
}
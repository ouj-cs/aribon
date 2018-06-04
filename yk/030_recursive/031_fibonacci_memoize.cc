#include<bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAX_N=10000;
int memo[MAX_N+1];
/// Returns Fibonacci number of n.
int fib(int n){
  if(n<=1)return n;
  if(memo[n]!=0)return memo[n];
  return memo[n]=fib(n-1)+fib(n-2);
}

main(){
  for(int i=0;i<100;++i){
    printf("%ld %ld\n",i,fib(i));
  }
}

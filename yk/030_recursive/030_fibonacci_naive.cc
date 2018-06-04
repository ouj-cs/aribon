#include<bits/stdc++.h>
using namespace std;

/// Returns Fibonacci number of n.
int fib(int n){
  if(n<=1)return n;
  return fib(n-1)+fib(n-2);
}

main(){
  for(int i=0;i<40;++i){
    printf("%d %d\n",i,fib(i));
  }
}

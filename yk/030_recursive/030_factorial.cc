#include<bits/stdc++.h>
using namespace std;

/// Returns the factorial of n.
int fact(int n){
  assert(n>=0);
  if(n==0)return 1;
  return n*fact(n-1);
}

main(){
  for(int i=0;i<10;++i){
    printf("%d %d\n",i,fact(i));
  }
}

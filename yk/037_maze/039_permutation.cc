#include<bits/stdc++.h>
using namespace std;
const int MAX_N=10;

bool used[MAX_N];
int perm[MAX_N];
/// Produces n! permutations of {0, 1, ..., n}.
void permutation1(int pos,int n){
  if(pos==n){
    for(int i=0;i<n;++i){
      printf("%d,",perm[i]);
    }
    cout<<endl;
    return;
  }
  for(int i=0;i<n;++i){
    if(!used[i]){
      perm[pos]=i;
      used[i]=true;
      permutation1(pos+1,n);
      used[i]=false;
    }
  }
}

int perm2[MAX_N];
void permutation2(int n){
  for(int i=0;i<n;++i){
    perm2[i]=i;
  }
  do{
    for(int i=0;i<n;++i){
      printf("%d,",perm2[i]);
    }
    cout<<endl;
  }while(next_permutation(perm2,perm2+n));
}

main(){
  permutation1(0,4);
  permutation2(4);
}

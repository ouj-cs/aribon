/// @file
/// @version Accepted.
#include<bits/stdc++.h>
using namespace std;
int N,A[10],B[10],C[10];
bool dfs(int i,int n_b,int n_c){
  if(i==10)return true;
  bool is_b;
  B[n_b]=A[i];
  if(n_b>=1&&B[n_b]<B[n_b-1]){
    is_b=false;
  }else{
    is_b=dfs(i+1,n_b+1,n_c);
  }
  bool is_c;
  C[n_c]=A[i];
  if(n_c>=1&&C[n_c]<C[n_c-1]){
    is_c=false;
  }else{
    is_c=dfs(i+1,n_b,n_c+1);
  }
  if(is_b||is_c)return true;
  return false;
}
void solve(){
  puts(dfs(0,0,0)?"YES":"NO");
}
main(){
  cin>>N;
  for(int i=0;i<N;++i){
    for(int i=0;i<10;++i)cin>>A[i];
    solve();
  }
}

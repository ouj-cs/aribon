/// @file
/// @version Accepted.
#include<algorithm>
#include<cstdio>
#define int long long
#define p(f,...) //printf(f,##__VA_ARGS__)
using namespace std;
int N,S,C[10000],Y[10000];
void solve(){
  int sum=0;
  for(int i=0;i<N;++i){
    int c_min=0x3f3f3f3f;
    for(int j=0;j<i;++j){
      C[j]+=S;
      c_min=min(c_min,C[j]);
    }
    c_min=min(c_min,C[i]);
    p("add=%lld %lld\n",c_min*Y[i],c_min);
    sum+=c_min*Y[i];
  }
  printf("%lld\n",sum);
}
main(){
  scanf("%lld%lld",&N,&S);
  for(int i=0;i<N;++i){
    scanf("%lld%lld",&C[i],&Y[i]);
  }
  solve();
}

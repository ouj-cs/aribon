/// @file
/// @version Time Limit Exceeded.
#include<algorithm>
#include<cstdio>
#include<vector>
#define p(f,...) //printf(f,##__VA_ARGS__)
using namespace std;
struct Cow{int A,B,stall,name;};
int N;
vector<Cow> xs;
bool compareA(const Cow&left,const Cow&right){
  return left.A<right.A;
}
bool compareName(const Cow&left,const Cow&right){
  return left.name<right.name;
}
int solve(){
  sort(xs.begin(),xs.end(),compareA);
  int stall=1;
  while(true){
    bool is_found=false;
    int free=1;
    for(int i=1;i<=N;++i){
      if(xs[i].stall!=-1)continue;
      const int A=xs[i].A;
      const int B=xs[i].B;
      if(A>=free){
        p("A,B=%d,%d\n",A,B);
        free=B+1;
        xs[i].stall=stall;
      }else{
        is_found=true;
      }
    }
    if(!is_found)break;
    ++stall;
  }
  return stall;
}
main(){
  scanf("%d",&N);
  xs.resize(N+1);
  xs[0].A=xs[0].B=xs[0].stall=xs[0].name=-1;   // dummy.
  for(int i=1;i<=N;++i){
    scanf("%d%d",&xs[i].A,&xs[i].B);
    xs[i].name=i;
    xs[i].stall=-1;
  }
  const int n_stalls=solve();
  sort(xs.begin(),xs.end(),compareName);
  printf("%d\n",n_stalls);
  for(int i=1;i<=N;++i){
    printf("%d\n",xs[i].stall);
  }
}

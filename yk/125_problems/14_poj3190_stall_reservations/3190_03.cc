/// @file
/// @version Accepted.
/// referenced: http://d.hatena.ne.jp/komiyam/20120804/1344081569
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#define p(f,...) //printf(f,##__VA_ARGS__)
using namespace std;
struct Cow{int A,B,name;};
int N;
vector<Cow>xs;
vector<int>stalls;
bool compareA(const Cow&left,const Cow&right){
  return left.A<right.A;
}
struct compareB{
  bool operator()(const Cow&left,const Cow&right){
    return left.B>right.B;
  }
};
void printQueue(const priority_queue<Cow,vector<Cow>,compareB>&q){
  p("queue=");
  priority_queue<Cow,vector<Cow>,compareB>xs=q;
  while(!xs.empty()){
    Cow x=xs.top();
    p("(%d,%d,%d,%d),",x.A,x.B,x.stall,x.name);
    xs.pop();
  }
  p("\n");
}
int solve(){
  sort(xs.begin(),xs.end(),compareA);
  priority_queue<Cow,vector<Cow>,compareB>q;
  for(int i=1;i<=N;++i){
    // printQueue(q);
    if(q.empty()||xs[i].A<q.top().B){
      q.push(xs[i]);
      stalls[xs[i].name]=q.size();
    }else{
      Cow x=q.top();
      q.pop();
      stalls[xs[i].name]=stalls[x.name];
      q.push(xs[i]);
    }
  }
  return q.size();
}
main(){
  scanf("%d",&N);
  xs.resize(N+1);
  xs[0].A=xs[0].B=xs[0].name=-1;   // dummy.
  stalls.resize(N+1);
  for(int i=1;i<=N;++i){
    scanf("%d%d",&xs[i].A,&xs[i].B);
    ++xs[i].B;
    xs[i].name=i;
  }
  const int n_stalls=solve();
  printf("%d\n",n_stalls);
  for(int i=1;i<=N;++i){
    printf("%d\n",stalls[i]);
  }
}

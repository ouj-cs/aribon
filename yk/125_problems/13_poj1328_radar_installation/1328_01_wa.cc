/// @file
/// @version Wrong Answer.
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#define p(f,...) //printf(f,##__VA_ARGS__)
using namespace std;
typedef pair<int,int>Pair;
int n;
double d;
Pair xs[1000];
int solve(){
  bool is_radar=false;
  int ans=0;
  double x_radar;
  for(int i=0;i<n;++i){
    const double x=xs[i].first;
    const double y=xs[i].second;
    p("x,y=%f,%f\n",x,y);
    if(y>d)return -1;
    if(is_radar){
      const double x_distance=abs(x_radar-x);
      const double distance=sqrt(x_distance*x_distance+y*y);
      const bool is_in=distance<=d;
      p("is_in=%d\n",is_in);
      if(!is_in)is_radar=false;
    }
    if(!is_radar){
      ++ans;
      x_radar=x+sqrt(d*d-y*y);
      p("x_radar=%f\n",x_radar);
      is_radar=true;
    }
  }
  return ans;
}
main(){
  int i=1;
  while(true){
    scanf("%d%lf",&n,&d);
    if(n==0)break;
    for(int i=0;i<n;++i){
      int x,y;
      scanf("%d%d",&x,&y);
      xs[i]=make_pair(x,y);
    }
    sort(xs,xs+n);
    int ans=solve();
    printf("Case %d: %d\n",i++,ans);
  }
}

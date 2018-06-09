/// @file
/// @version Accepted.
#include<iostream>
using namespace std;
const int INF=1000000;
const int dy[]={-1,0,0,1};
const int dx[]={0,-1,1,0};
int w,h,intss[20][20];
int y_start,x_start;
bool isInside(int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}
bool isBlock(int y,int x){
  return intss[y][x]==1;
}
bool isGoal(int y,int x){
  return intss[y][x]==3;
}
int dfs(int depth,int y,int x){
  if(depth==10)return -1;
  int dfs_min=INF;
  for(int i=0;i<4;++i){
    int y_next=y+dy[i];
    int x_next=x+dx[i];
    if(!isInside(y_next,x_next))continue;
    if(isBlock(y_next,x_next))continue;
    while(true){
      if(!isInside(y_next,x_next))break;
      if(isGoal(y_next,x_next))return depth+1;
      if(isBlock(y_next,x_next)){
        intss[y_next][x_next]=0;  // The block disappears.
        int x=dfs(depth+1,y_next-dy[i],x_next-dx[i]);
        intss[y_next][x_next]=1;
        if(x!=-1)dfs_min=min(dfs_min,x);
        break;
      }
      y_next+=dy[i];
      x_next+=dx[i];
    }
  }
  if(dfs_min==INF){
    return -1;
  }else{
    return dfs_min;
  }
}
void solve(){
  int n=dfs(0,y_start,x_start);
  cout<<n<<endl;
}
int main(){
  while(true){
    cin>>w>>h;
    if(w==0)break;
    for(int y=0;y<h;++y){
      for(int x=0;x<w;++x){
        cin>>intss[y][x];
        if(intss[y][x]==2){
          y_start=y;
          x_start=x;
          intss[y][x]==0;
        }
      }
    }
    solve();
  }
}

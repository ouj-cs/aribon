/// @file
/// @version Accepted.
#include<bits/stdc++.h>
using namespace std;
constexpr int INF=0x3f3f3f3f;
constexpr int dy[]={-1,0,0,1};
constexpr int dx[]={0,-1,1,0};
int H,W,N;
char charss[1000][1000];
int ys[255];
int xs[255];
struct Point{int y,x;};
int d[1000][1000];  // Distances;
int bfs(char from,char to){
  queue<Point>q;
  for(int y=0;y<H;++y){
    for(int x=0;x<W;++x){
      d[y][x]=INF;
    }
  }
  q.push({ys[from],xs[from]});
  d[ys[from]][xs[from]]=0;
  while(q.size()){
    Point p=q.front();
    q.pop();
    if(p.y==ys[to]&&p.x==xs[to])break;
    for(int i=0;i<4;++i){
      const int y_next=p.y+dy[i];
      const int x_next=p.x+dx[i];
      if(y_next<0||H<=y_next)continue;
      if(x_next<0||W<=x_next)continue;
      if(charss[y_next][x_next]=='X')continue;  // Wall.
      if(d[y_next][x_next]!=INF)continue;       // Already visited.
      q.push({y_next,x_next});
      d[y_next][x_next]=d[p.y][p.x]+1;
    }
  }
  return d[ys[to]][xs[to]];
}
void solve(){
  int len=0;
  for(char c='0';c<'0'+N;++c){
    len+=bfs(c,c+1);
  }
  cout<<len<<endl;
}
main(){
  cin>>H>>W>>N;
  for(int y=0;y<H;++y){
    for(int x=0;x<W;++x){
      char c;
      cin>>c;
      if(c=='S')c='0';
      ys[c]=y;
      xs[c]=x;
      charss[y][x]=c;
    }
  }
  solve();
}

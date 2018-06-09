/// @file
/// @version Accepted.
/// referenced: http://arrows1011.hatenablog.com/entry/2015/01/13/001312
#include<iostream>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=302;  // Meteor destroys [0,301]. Bessie runs to [0,302].
const int dx[]={0,-1,1,0};
const int dy[]={-1,0,0,1};
struct Point{
  int x,y,z;
  Point(int x,int y,int z):x(x),y(y),z(z){}
};
int M;
bool is_visited[MAX][MAX];
int times[MAX][MAX];
int bfs(){
  queue<Point>q;
  is_visited[0][0]=true;
  q.push(Point(0,0,0));
  while(q.size()){
    Point p=q.front();
    q.pop();
    if(times[p.y][p.x]==INF)return p.z;
    for(int i=0;i<4;++i){
      const int x=p.x+dx[i];
      const int y=p.y+dy[i];
      if(x<0||MAX<=x)continue;
      if(y<0||MAX<=y)continue;
      if(p.z+1>=times[y][x])continue;
      if(is_visited[y][x])continue;
      is_visited[y][x]=true;
      q.push(Point(x,y,p.z+1));
    }
  }
  return -1;
}
void solve(){
  int x=bfs();
  cout<<x<<endl;
}
int main(){
  fill(times[0],times[0]+MAX*MAX,INF);
  cin>>M;
  for(int i=0;i<M;++i){
    int X,Y,T;
    cin>>X>>Y>>T;
    times[Y][X]=min(times[Y][X],T);
    for(int i=0;i<4;++i){
      const int x=X+dx[i];
      const int y=Y+dy[i];
      if(x<0||MAX<=x)continue;
      if(y<0||MAX<=y)continue;
      times[y][x]=min(times[y][x],T);
    }
  }
  solve();
}

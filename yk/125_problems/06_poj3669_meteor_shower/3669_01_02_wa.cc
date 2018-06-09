/// @file
/// @version Wrong Answer.
#include<iostream>
#include<list>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=303;
const int dx[]={0,-1,1,0};
const int dy[]={-1,0,0,1};
struct Point{
  int x,y;
  bool operator==(const Point&other)const{
    return x==other.x&&y==other.y;
  }
};
struct Meteor{
  Point p;
  int t;
  bool operator<(const Meteor&other)const{
    return t<other.t;
  }
};
int M;
bool is_visited[MAX][MAX];
bool is_destroyed[MAX][MAX];
int times[MAX][MAX];
list<Meteor>meteors;
int f0(){
  int x_min=INF;
  for(int y=0;y<MAX;++y){
    for(int x=0;x<MAX;++x){
      if(!is_destroyed[x][y]){
        x_min=min(x_min,times[x][y]);
      }
    }
  }
  if(x_min==INF)return -1;
  return x_min;
}
int bfs(){
  for(int y=0;y<MAX;++y){
    for(int x=0;x<MAX;++x){
      times[x][y]=INF;
    }
  }
  queue<Meteor>q;
  Meteor m_zero;
  m_zero.p.x=0;
  m_zero.p.y=0;
  m_zero.t=0;
  is_visited[0][0]=true;
  q.push(m_zero);
  int time=0;
  int time_end=INF;
  while(q.size()){
    Meteor m=q.front();
    q.pop();
    time=max(time,m.t);
    // printf("%d %d %d\n",m.p.x,m.p.y,m.t);
    while(true){  // Does meteors.
      if(meteors.empty())break;
      Meteor m=meteors.front();
      if(m.t>time)break;
      meteors.pop_front();
      is_destroyed[m.p.x][m.p.y]=true;
      for(int i=0;i<4;++i){
        int x=m.p.x+dx[i];
        int y=m.p.y+dy[i];
        if(x<0||MAX<=x)continue;
        if(y<0||MAX<=y)continue;
        is_destroyed[x][y]=true;
      }
    }
    if(is_destroyed[m.p.x][m.p.y])continue;
    times[m.p.x][m.p.y]=time;
    if(meteors.empty())break;
    for(int i=0;i<4;++i){
      int x=m.p.x+dx[i];
      int y=m.p.y+dy[i];
      if(x<0||MAX<=x)continue;
      if(y<0||MAX<=y)continue;
      if(is_visited[x][y])continue;
      if(is_destroyed[x][y])continue;
      Meteor m_next;
      m_next.p.x=x;
      m_next.p.y=y;
      m_next.t=time+1;
      is_visited[x][y]=true;
      q.push(m_next);
    }
  }
  return f0();
}
void solve(){
  int x=bfs();
  cout<<x<<endl;
}
int main(){
  cin>>M;
  for(int i=0;i<M;++i){
    Meteor m;
    cin>>m.p.x>>m.p.y>>m.t;
    meteors.push_back(m);
  }
  meteors.sort();
  solve();
}

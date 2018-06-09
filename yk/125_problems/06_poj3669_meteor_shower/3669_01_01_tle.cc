/// @file
/// @version Time Limit Exceeded.
#include<iostream>
#include<list>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
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
bool is_visited[300][300];
bool is_destroyed[300][300];
list<Meteor>meteors;
int bfs(){
  queue<Meteor>q;
  Meteor m_zero;
  m_zero.p.x=0;
  m_zero.p.y=0;
  m_zero.t=0;
  q.push(m_zero);
  int time=0;
  while(q.size()){
    Meteor m=q.front();
    q.pop();
    time=max(time,m.t);
    is_visited[m.p.x][m.p.y]=true;
    // printf("%d %d %d\n",m.p.x,m.p.y,m.t);
    while(true){  // Does meteors.
      if(meteors.empty())break;
      Meteor m=meteors.front();
      if(m.t>time)break;
      meteors.pop_front();
      for(int i=0;i<4;++i){
        int x=m.p.x+dx[i];
        int y=m.p.y+dy[i];
        if(x<0||300<=x)continue;
        if(y<0||300<=y)continue;
        is_destroyed[x][y]=true;
      }
    }
    if(is_destroyed[m.p.x][m.p.y])continue;
    if(meteors.empty())return time;
    for(int i=0;i<4;++i){
      int x=m.p.x+dx[i];
      int y=m.p.y+dy[i];
      if(x<0||300<=x)continue;
      if(y<0||300<=y)continue;
      if(is_visited[x][y])continue;
      if(is_destroyed[x][y])continue;
      Meteor m_next;
      m_next.p.x=x;
      m_next.p.y=y;
      m_next.t=time+1;
      q.push(m_next);
    }
  }
  return -1;
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

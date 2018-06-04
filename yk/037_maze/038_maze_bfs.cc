#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100;
const int MAX_M=100;

const int INF=100'000'000;
typedef pair<int,int>P;
char maze[MAX_N][MAX_M+1];
int N,M;
int sx,sy;            // start
int gx,gy;            // goal
int d[MAX_N][MAX_M];  // distance
int dx[4]={1,0,-1,-0};
int dy[4]={0,1,0,-1};
/// @brief Returns shortest distance from the start to the goal.
int bfs(){
  queue<P>q;
  for(int i=0;i<N;++i)  // Inits the distance of every cell to INF.
    for(int j=0;j<M;++j)d[i][j]=INF;
  q.push(P(sx,sy));
  d[sx][sy]=0;
  while(q.size()){
    P p=q.front();q.pop();
    if(p.first==gx&&p.second==gy)break;
    for(int i=0;i<4;++i){     // 4 adjacent cells.
      int nx=p.first+dx[i];   // next x.
      int ny=p.second+dy[i];  // next y.
      // if in range and not wall and not yet visited.
      if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF){
        q.push(P(nx,ny));
        d[nx][ny]=d[p.first][p.second]+1;
      }
    }
  }
  return d[gx][gy];
}
void solve(){
 int res=bfs();
 printf("%d\n",res); 
}

main(){
  cin>>N>>M;
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      cin>>maze[i][j];
      if(maze[i][j]=='S'){  // Sets start.
        sx=i;
        sy=j;
      }
      if(maze[i][j]=='G'){  // Sets goal.
        gx=i;
        gy=j;
      }
    }
  }
  solve();
}

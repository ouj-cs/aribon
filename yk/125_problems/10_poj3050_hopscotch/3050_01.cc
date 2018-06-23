/// @file
/// @version Accepted.
#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int dy[]={-1,0,0,1};
const int dx[]={0,-1,1,0};
int cellss[5][5],n_insert;
bool is_visited[5][5];
vector<int>xs(6);
set<vector<int> >xss;
void dfs(int len,int y,int x){
  if(len==6){
    xss.insert(xs);
    ++n_insert;
    return;
  }
  xs[len]=cellss[y][x];
  for(int i=0;i<4;++i){
    const int y_next=y+dy[i];
    const int x_next=x+dx[i];
    if(y_next<0||5<=y_next)continue;
    if(x_next<0||5<=x_next)continue;
    dfs(len+1,y_next,x_next);
  }
}
void solve(){
  for(int y=0;y<5;++y){
    for(int x=0;x<5;++x){
      dfs(0,y,x);
    }
  }
}
int main(){
  for(int y=0;y<5;++y){
    for(int x=0;x<5;++x){
      cin>>cellss[y][x];
    }
  }
  solve();
  // printf("n_insert=%d\n",n_insert);
  cout<<xss.size()<<endl;
}

/// @file
/// @version Accepted.
#include<bits/stdc++.h>
using namespace std;
constexpr array<int,4>dx={-4,-1,1,4};
vector<int>ints(8);
int iZero(vector<int>&xs){
  for(int i=0;i<xs.size();++i){
    if(xs[i]==0)return i;
  }
  assert(false);
}
map<vector<int>,int>d;
void bfs(){
  queue<vector<int>>q;
  vector<int>start={0,1,2,3,4,5,6,7};
  q.push(start);
  d[start]=0;
  while(q.size()){
    vector<int>from=q.front();
    q.pop();
    for(int i=0;i<4;++i){
      const int i_now=iZero(from);
      const int i_next=i_now+dx[i];
      if(i_next<0||8<=i_next)continue;
      if(i_now==3&&i_next==4)continue;
      if(i_now==4&&i_next==3)continue;
      vector<int>to=from;
      swap(to[i_now],to[i_next]);
      if(d.find(to)!=d.end())continue;
      q.push(to);
      d[to]=d[from]+1;
    }
  }
}
void solve(){
  cout<<d[ints]<<endl;
}
main(){
  bfs();
  while(cin>>ints[0]){
    for(int i=1;i<8;++i)cin>>ints[i];
    solve();
  }
}

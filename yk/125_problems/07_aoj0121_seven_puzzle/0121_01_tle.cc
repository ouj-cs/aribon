/// @file
/// @version Time Limit Exceeded.
#include<bits/stdc++.h>
using namespace std;
constexpr array<int,4>dx={-4,-1,1,4};
vector<int>ints(8);
void print(vector<int>&xs){
  for(auto&x:xs)cout<<x<<",";
  cout<<endl;
}
bool isDone(vector<int>&xs){
  for(int i=0;i<xs.size();++i){
    if(xs[i]!=i)return false;
  }
  return true;
}
int iZero(vector<int>&xs){
  for(int i=0;i<xs.size();++i){
    if(xs[i]==0)return i;
  }
  assert(false);
}
struct State{
  vector<int>xs;
  int len;
};
set<vector<int>>visited;
int bfs(){
  visited.clear();
  queue<State>q;
  q.push({ints,0});
  while(q.size()){
    State s=q.front();
    q.pop();
    vector<int>&from=s.xs;
    int len=s.len;
    if(isDone(from))return len;
    for(int i=0;i<4;++i){
      const int i_now=iZero(from);
      const int i_next=i_now+dx[i];
      if(i_next<0||8<=i_next)continue;
      if(i_now==3&&i_next==4)continue;
      if(i_now==4&&i_next==3)continue;
      vector<int>to=from;
      swap(to[i_now],to[i_next]);
      if(visited.find(to)!=visited.end())continue;
      q.push({to,len+1});
    }
    visited.insert(from);
  }
}
void solve(){
  int len=bfs();
  cout<<len<<endl;
}
main(){
  while(cin>>ints[0]){
    for(int i=1;i<8;++i)cin>>ints[i];
    solve();
  }
}

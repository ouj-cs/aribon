/// @file
/// @version Accepted.
#include<bits/stdc++.h>
using namespace std;
constexpr char DONE='.';
constexpr int dx[]={0,-1,1,0};
constexpr int dy[]={-1,0,0,1};
int H,W;
char charss[100][100];
bool isValid(int h,int w){
  return 0<=h&&h<H&&0<=w&&w<W;
}
void dfs(char c,int h,int w){
  if(charss[h][w]!=c)return;
  charss[h][w]=DONE;
  for(int i=0;i<4;++i){
    const int h1=h+dy[i];
    const int w1=w+dx[i];
    if(isValid(h1,w1))dfs(c,h1,w1);
  }
}
void solve(){
  int n_count=0;
  for(int h=0;h<H;++h){
    for(int w=0;w<W;++w){
      const char c=charss[h][w];
      if(c!=DONE){
        dfs(c,h,w);
        ++n_count;
      }
    }
  }
  cout<<n_count<<endl;
}
main(){
  while(true){
    cin>>H>>W;
    if(H==0)break;
    for(int h=0;h<H;++h){
      for(int w=0;w<W;++w){
        cin>>charss[h][w];
      }
    }
    solve();
  }
}

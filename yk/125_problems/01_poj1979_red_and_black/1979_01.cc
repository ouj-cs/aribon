/// @file
/// @version Accepted.
#include<iostream>
using namespace std;
const char VISITED='x';
const int dy[]={-1,0,0,1};
const int dx[]={0,-1,1,0};
int W,H;
char charss[20][20];
int start_x,start_y;
int dfs(int y,int x){
  if(y<0||H<=y||x<0||W<=x)return 0;
  if(charss[y][x]=='#'||charss[y][x]==VISITED)return 0;
  charss[y][x]=VISITED;
  int sum=1;
  for(int i=0;i<4;++i){
    const int y_next=y+dy[i];
    const int x_next=x+dx[i];
    sum+=dfs(y_next,x_next);
  }
  return sum;
}
void solve(){
  int n=dfs(start_y,start_x);
  cout<<n<<endl;
}
int main(){
  while(true){
    cin>>W>>H;
    if(W==0)break;
    for(int h=0;h<H;++h){
      for(int w=0;w<W;++w){
        cin>>charss[h][w];
        if(charss[h][w]=='@'){
          start_y=h;
          start_x=w;
        }
      }
    }
    solve();
  }
}

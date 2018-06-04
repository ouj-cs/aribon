#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100;
const int MAX_M=100;

int N,M;  // The garden size N*M.
char field[MAX_N][MAX_M+1];
void dfs(int x,int y){
  field[x][y]='.';              // Consumes.
  for(int dx=-1;dx<=1;++dx){    // O(3*3)=O(9).
    for(int dy=-1;dy<=1;++dy){  // O(3).
      int nx=x+dx,ny=y+dy;      // next x, next y.
      if(0<=nx&&nx<N&&0<=ny&&ny<=M&&field[nx][ny]=='W')dfs(nx,ny);
    }
  }
}
/// O(N*M). Calls dfs() 8*N*M times at maximum.
void solve(){
  int res=0;
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      if(field[i][j]=='W'){  // Found water.
        dfs(i,j);
        ++res;
      }
    }
  }
  printf("%d\n",res);
}

main(){
  cin>>N>>M;
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      cin>>field[i][j];
    }
    cin.ignore(1);
  }
  solve();
}

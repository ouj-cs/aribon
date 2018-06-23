/// @file
/// @version Accepted.
/// referenced: http://d.hatena.ne.jp/komiyam/20100905/1283656175
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int>Pair;
typedef vector<Pair>Pairs;
int N,T;
Pairs ses;
void solve(){
  int start=1,end=0,i=0,n_cows=0;
  while(true){
    bool updated=false;
    for(;i<N&&ses[i].first<=start;++i){
      end=max(end,ses[i].second);
      updated=true;
    }
    ++n_cows;
    if(end>=T){
      printf("%d\n",n_cows);
      break;
    }
    if(i==N||!updated){
      printf("-1\n");
      break;
    }
    start=end+1;
  }
}
int main(){
  scanf("%d%d",&N,&T);
  for(int i=0;i<N;++i){
    int start,end;
    scanf("%d%d",&start,&end);
    Pair se;
    se.first=start;
    se.second=end;
    ses.push_back(se);
  }
  sort(ses.begin(),ses.end());
  solve();
}

/// @file
/// @version Wrong Answer.
/// referenced: http://d.hatena.ne.jp/komiyam/20100905/1283656175
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int>Pair;
typedef vector<Pair>Pairs;
int N,T;
Pairs ses;
bool compareEnd(const Pair&left,const Pair&right){
  return left.second<right.second;
}
void solve(){
  int start=1,n_cows=0;
  Pairs::iterator left,right=ses.begin();
  while(true){
    left=right;
    right=upper_bound(left,ses.end(),make_pair(start,0x3f3f3f3f));
    sort(left,right,compareEnd);
    int end=(*(right-1)).second;
    ++n_cows;
    if(end>=T){
      printf("%d\n",n_cows);
      break;
    }
    if(right==ses.end()||left==right){
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

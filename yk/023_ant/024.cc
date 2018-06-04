#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1000000;

int L,n;
int x[MAX_N];
/// O(n).
void solve(){
  int minT=0;             // minimum time.
  for(int i=0;i<n;++i){   // O(n).
    minT=max(minT,min(x[i],L-x[i]));
  }
  int maxT=0;             // maximum time.
  for(int i=0;i<n;++i){   // O(n).
    maxT=max(maxT,max(x[i],L-x[i]));
  }
  printf("%d %d\n",minT,maxT);
}

main(){
  cin>>L>>n;
  for(int i=0;i<n;++i)cin>>x[i];
  solve();
}

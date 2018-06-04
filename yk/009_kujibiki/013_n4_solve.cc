#include<bits/stdc++.h>
const int MAX_N=50;
int n,m,k[MAX_N];
void solve(){
  bool is_found=false;
  for(int a=0;a<n;++a){         // O(n^4).
    for(int b=0;b<n;++b){       // O(n^3).
      for(int c=0;c<n;++c){     // O(n^2).
        for(int d=0;d<n;++d){   // O(n).
          if(k[a]+k[b]+k[c]+k[d]==m)is_found=true;
        }
      }
    }
  }
  puts(is_found?"Yes":"No");
}
main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i)scanf("%d",&k[i]);
  solve();
}

#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100;

int n,a[MAX_N];
void solve(){
  int len_max=0;
  for(int i=0;i<n;++i){         // O(n^3).
    for(int j=i+1;j<n;++j){     // O(n^2).
      for(int k=j+1;k<n;++k){   // O(n).
        const int total=a[i]+a[j]+a[k];
        const int longest=max(a[i],max(a[j],a[k]));
        const int short2=total-longest;
        if(longest<short2){
          len_max=max(len_max,total);
        }
      }
    }
  }
  printf("%d\n",len_max);
}

main(){
  cin>>n;
  for(int i=0;i<n;++i)cin>>a[i];
  solve();
}

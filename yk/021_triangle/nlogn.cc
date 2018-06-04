#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100;

int n,a[MAX_N];
/// O(n*log(n)).
void solve(){
  sort(a,a+n);      // O(n*log(n)).
  reverse(a,a+n);   // O(n).
  int len_max=0;
  for(int i=0;i<n-2;++i){     // O(n).
    const int longest=a[i];
    const int short2=a[i+1]+a[i+2];
    const int total=longest+short2;
    if(longest<short2){
      len_max=max(len_max,total);
    }
  }
  printf("%d\n",len_max);
}

main(){
  cin>>n;
  for(int i=0;i<n;++i)cin>>a[i];
  solve();
}

/// @file
/// @version Accepted.
#include<bits/stdc++.h>
using namespace std;
int R,C;
vector<vector<int>>a,a2;
void print(const vector<vector<int>>&xss){
  cout<<"Printing."<<endl;
  for(auto&xs:xss){
    for(auto&x:xs)cout<<x<<",";
    cout<<endl;
  }
}
void negateIt(vector<int>*xs){
  auto&vec=*xs;
  for(auto&x:vec)x=!x;
}
void solve(){
  int bits=pow(2,R),n_max=0;
  while(bits--){
    a2=a;
    for(int y=0;y<R;++y){
      if(bits>>y&1){
        negateIt(&a2[y]);
      }
    }
    int sum=0;
    for(int x=0;x<C;++x){
      int sum_c=0;
      for(int y=0;y<R;++y){
        sum_c+=a2[y][x];
      }
      sum+=max(sum_c,R-sum_c);
    }
    n_max=max(n_max,sum);
  }
  cout<<n_max<<endl;
}
main(){
  while(true){
    cin>>R>>C;
    if(R==0)break;
    a=vector<vector<int>>(R,vector<int>(C));
    for(int y=0;y<R;++y){
      for(int x=0;x<C;++x){
        cin>>a[y][x];
      }
    }
    solve();
  }
}

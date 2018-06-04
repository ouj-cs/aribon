#include<bits/stdc++.h>
using namespace std;
const int MAX_N=20;

int a[MAX_N];
int n,k;
/// @brief Returns true if any leaf = sum, false otherwise.
/// Recursively represents a binary tree.
/// Every leaf has the same depth n.
/// The number of leaves is 2^(n+1).
bool dfs(int i,int sum){
  if(i==n)return sum==k;              // This call represents a leaf.
  if(dfs(i+1,sum))return true;        // Doesn't use a[i].
  if(dfs(i+1,sum+a[i]))return true;   // Uses a[i].
  return false;                       // Not found in descendants.
}
void solve(){
  if(dfs(0,0))printf("Yes\n");  // Checks a[0] with accumulator value 0.
  else printf("No\n");
}

main(){
  cin>>n;
  for(int i=0;i<n;++i)cin>>a[i];
  cin>>k;
  solve();
}

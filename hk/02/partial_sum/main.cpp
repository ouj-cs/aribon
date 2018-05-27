#include <cstdio>
int n;
int a[20];
int k;

bool dfs(int v, int dep) {
  if (dep == n) {
    return v == k;
  }
  else {
    return dfs(v + a[dep], dep + 1) | dfs(v, dep + 1);
  }
}

int main() {
  int i;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &k);

  if (dfs(0, 0)) printf("Yes\n");
  else printf("No\n");
  
  return 0;
}

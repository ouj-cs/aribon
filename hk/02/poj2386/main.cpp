#include <cstdio>
bool check[100][100];
char Y[100][100];
int N, M;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

void search_lake(int x, int y) {
  check[y][x] = true;
  for (int i = 0; i < 8; i++) {
    if (Y[y+dy[i]][x+dx[i]] == 'W' && !check[y+dy[i]][x+dx[i]]) {
      search_lake(x+dx[i], y+dy[i]);
    }
  }
  return;
}

int main() {
  scanf("%d\n", &N);
  scanf("%d\n", &M);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%c\n", &Y[y][x]);
      printf("%c",Y[y][x]);
    }
    printf("\n");
  }
  int ans = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (Y[y][x] == 'W' && !check[y][x]) {
	ans++;
	search_lake(x, y);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

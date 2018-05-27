#include <cstdio>
bool check[100][100];
char Y[100][100];
int N, M;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

bool check_valid(int x, int y) {
  return (0 <= y && y < N && 0 <= x && y < M);
}

void search_lake(int x, int y) {
  check[y][x] = true;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (check_valid(nx, ny) && Y[ny][nx] == 'W' && !check[ny][nx]) {
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
    }
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

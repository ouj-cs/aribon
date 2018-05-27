#include <cstdio>
#include <queue>
using namespace std;

bool check[100][100];
char L[100][100];
int N, M;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

typedef struct {
  int x;
  int y;
  int count;
} qe;

bool check_valid(int x, int y) {
  return (0 <= y && y < N && 0 <= x && y < M);
}

int main() {
  scanf("%d\n", &N);
  scanf("%d\n", &M);
  int sx, sy;
  int gx, gy;  
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%c\n", &L[y][x]);
      if (L[y][x] == 'S') {
	sx = x;
	sy = y;
      }
      else if (L[y][x] == 'G') {
	gx = x;
	gy = y;
      }
    }
  }
  
  int ans = 0;
  queue<qe> search;
  // start point.
  qe sp = {sx, sy, 0};
  search.push(sp);

  while (!search.empty()) {
    // current point.
    qe cp = search.front(); search.pop();
    if (cp.x == gx && cp.y == gy) {
      ans = cp.count;
      break;
    }

    // convert path to wall
    L[cp.y][cp.x] = '#';
    
    for (int i = 0; i < 4; i++) {
      int nx = cp.x + dx[i];
      int ny = cp.y + dy[i];
      if (check_valid(nx, ny) && L[ny][nx] != '#') {
	qe np = {nx, ny, cp.count + 1};
	search.push(np);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}

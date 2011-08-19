#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

const int INF = 1000000;
const int MAX_N = 100;
const int MAX_M = 100;

typedef pair<int, int> P;
char maze[MAX_N][MAX_M+1];  // maze
int n, m;   // size of maze
int sx, sy; // start position
int gx, gy; // goal position

//shortest path for each point
int d[MAX_N][MAX_M];

//vector for for moving direction
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//solve the shortest path from (sx, sy) to (gx, gy)
int bfs() {
  queue<P> q;
  //initialize every point with INF before search 
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = INF;
    }
  }
  q.push(P(sx,sy));
  d[sx][sy] = 0;

  while(q.size()) {
    P tmp = q.front();
    q.pop();
    //if you find goal then you finish search 
    if ((tmp.first == gx)&&(tmp.second == gy)){
      break;
    }
    for(int i = 0; i < 4; i++) {
      int nx = tmp.first + dx[i];
      int ny = tmp.second + dy[i];

      if ((0 <= nx) && (nx < n) &&
	  (0 <= ny) && (ny < m) &&
	  (maze[nx][ny] != '#') &&
	  (d[nx][ny] == INF)) {
	// if d[nx][ny] == INF then it is a position that
	// you have already visited. 
	q.push(P(nx,ny));
	d[nx][ny] = d[tmp.first][tmp.second] + 1; 
      } 
    }
  }
  return d[gx][gy];
}

void solve() {
  int res = bfs();
  cout << res << endl; 
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "./a.out <input file>";
    return 1;
  }
  ifstream ifs(argv[1]);
  if (!ifs) {
    cout << "can't open file:" << argv[1] << endl; 
    return 1;
  }
  string buf;
  getline(ifs, buf);
  sscanf(buf.c_str(), "%d %d", &n, &m);
  
  for(int i = 0; i < n; i++) {
    getline(ifs, buf);
    for (int j = 0; j < m; j++) {
      maze[i][j] = buf[j];
      if (maze[i][j] == 'S') {
	sx = i;
	sy = j; 
      }
      if (maze[i][j] == 'G') {
	gx = i;
	gy = j;
      } 
    }
  }

  solve();

  return 0;
}

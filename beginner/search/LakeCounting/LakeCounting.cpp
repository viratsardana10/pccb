#include <iostream>
#include <fstream>
using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;

int n, m;
char field[MAX_N][MAX_M+1];

void dfs(int x, int y){
  field[x][y] = '.';

  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx;
      int ny = y + dy;
      if ((0 <= nx) && (nx < n) &&
          (0 <= ny) && (ny < m) &&
	  (field[nx][ny] == 'W')) {
	dfs(nx,ny);
      }
    }
  }
  return;
}

int solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (field[i][j] == 'W') {
	dfs(i, j);
	res++;
      }
    } 
  }
  return res;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return 1;
  } 
  cout << argv[0] << endl;
  cout << argv[1] << endl;
  ifstream ifs(argv[1]);
  string buf;

  getline(ifs, buf);
  sscanf(buf.c_str(),"%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    getline(ifs, buf);
    for (int j = 0; j < m; j++) {
      field[i][j] = buf[j];
    }
  }

  cout << solve() << endl;

  return 0;
}

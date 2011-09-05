#include <iostream>
using namespace std;

//input
namespace {
  const int MAX_N = 2000;
}
int N = 6;
char s[MAX_N + 1] = "ACDBCB";
char t[MAX_N + 1];

void solve(){
  int s_start = 0, s_end = N - 1;
  int t_pos = 0;

  while(s_start <= s_end) {
    bool left = false;
    for (int i = 0; s_start + i <= s_end; i++) {
      if (s[s_start + i] < s[s_end - i]) {
	left = true;
	break;
      } else if (s[s_start + i] > s[s_end - i]) {
	left = false;
	break;
      }
    }
    if (left) {
      t[t_pos++] = s[s_start++];
    } else {
      t[t_pos++] = s[s_end--];
    }
  }
}

int main() {
  solve();
  cout << t << endl;
  return 0;
}

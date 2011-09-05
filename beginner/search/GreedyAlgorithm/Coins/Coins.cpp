#include <iostream>
using namespace std;

//price of coin
const int V[6] = {1, 5, 10, 50, 100, 500} ;

//input
int C[6] = {3, 2, 1, 3, 0, 2};
int A = 620;

int solve(){
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    int t = min(A / V[i], C[i]); // amout of coin i
    A -= t*V[i];
    ans += t;
  }

  return ans;
}

int main(void) {
  cout << solve() << endl;
}

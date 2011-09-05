#include <iostream>
using namespace std;

const int MAX_N = 100000;

//input
int N = 5;
int s[MAX_N] = {1, 2, 4, 6, 8};
int t[MAX_N] = {3, 5, 7, 9, 10};

//pair array for sorting jobs
pair <int, int> itv[MAX_N];

int solve(){
  //pair is compared by a dictionary order
  //put t into first and s into second to sord in end time ascending order
  for (int i = 0; i < N; i++) {
    itv[i].first = t[i];
    itv[i].second = s[i]; 
  }
  sort(itv, itv+N);

  //t is the end time for a job that you choose last
  int ans = 0, t = 0;
  for (int i = 0; i < N; i++) {
    if (t < itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }

  return ans;
}

int main(){
  cout << solve() << endl;

  return 0;
}

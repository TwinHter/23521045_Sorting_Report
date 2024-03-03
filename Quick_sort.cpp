#include<iostream>
#include<time.h>
using namespace std;

// Calculate run time of function
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )
// *

const int SZ = 1000000 + 10;
int a[SZ], n;
int partition(int start, int end) {
  int pval = a[start], cnt = 0;
  for(int i=start+1; i<=end; i++) {
    if(a[i] <= pval) cnt++;
  }

  int pid = start + cnt;
  swap(a[pid], a[start]);
  int u = start, v = end;
  while(u < pid && v > pid) {
    while(a[u] <= a[pid]) u++;
    while(a[v] > a[pid]) v--;
    if(u < pid && v > pid) {
      swap(a[u++], a[v--]);
    }
  }
  return pid;
}
void Quick_sort(int start = 0, int end = n-1) {
  if(start >= end) return;
  int p = partition(start, end);
  Quick_sort(start, p-1);
  Quick_sort(p+1, end);
}
int main() {
  freopen("test_case/Test_5.inp", "r", stdin);
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];

  time__("Quick sort") {
    Quick_sort();
  }
  for(int i=1; i<n; i++) {
    if(a[i] < a[i-1]) {
      cout << "Not sorted\n";
      return 0;
    }
  }
}
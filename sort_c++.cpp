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
void Sorting_function_of_cpp() {
  sort(a, a+n);
} 
int main() {
  freopen("test_case/Test_5.inp", "r", stdin);
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  time__("sorting function of c++") {
    Sorting_function_of_cpp();
  }
  for(int i=1; i<n; i++) {
    if(a[i] < a[i-1]) {
      cout << "Not sorted\n";
      return 0;
    }
  }
}
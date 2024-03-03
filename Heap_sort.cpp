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
void heapify(int arr[], int N, int p) {
  int largest = p;
  int L = p*2+1, R = p*2+2;
  if(L < N && arr[L] > arr[largest]) largest = L;
  if(R < N && arr[R] > arr[largest]) largest = R;
  if(largest != p) {
    swap(arr[p], arr[largest]);
    heapify(arr, N, largest);
  }
}
void Heap_sort(int arr[], int N=n) {
  // Build Heap
  for(int i=N/2-1; i>=0; i--) 
    heapify(arr, N, i);
  
  for(int i=N-1; i>=0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
int main() {
  freopen("test_case/Test_5.inp", "r", stdin);
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  time__("Heap sort") {
    Heap_sort(a, n);
  }
  for(int i=1; i<n; i++) {
    if(a[i] < a[i-1]) {
      cout << "Not sorted\n";
      return 0;
    }
  }
}
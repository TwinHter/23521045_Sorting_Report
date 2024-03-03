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
void Merge(int arr[], int start, int mid, int end) {
  int left_sz = mid-start+1, right_sz = end-mid;
  int *left_arr = new int[left_sz], *right_arr = new int[right_sz];
  // can use left_arr and right_arr as vector instead
  for(int i=0; i<left_sz; i++) left_arr[i] = arr[i];
  for(int i=0; i<right_sz; i++) right_arr[i] = arr[i+left_sz];

  int left_id = 0, right_id = 0;
  for(int i=start; i<=end; i++) {
    if(left_id == left_sz || right_id == right_sz) {
      if(left_id < left_sz) arr[i] = left_arr[left_id++];
      else arr[i] = right_arr[right_id++];
    }
    else {
      if(left_arr[left_id] <= right_arr[right_id])
        arr[i] = left_arr[left_id++];
      else arr[i] = right_arr[right_id++];
    }
  } 
  delete(left_arr);
  delete(right_arr);
}
void Merge_sort(int arr[], int start=0, int end=n-1) {
  if(start >= end) return;
  int mid = start+(end-start)/2;
  Merge_sort(arr, start, mid);
  Merge_sort(arr, mid+1, end);
  Merge(arr, start, mid, end);
} 
int main() {
  freopen("test_case/Test_5.inp", "r", stdin);
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  time__("Merge sort") {
    Merge_sort(a);
  }
  for(int i=1; i<n; i++) {
    if(a[i] < a[i-1]) {
      cout << "Not sorted\n";
      return 0;
    }
  }
}

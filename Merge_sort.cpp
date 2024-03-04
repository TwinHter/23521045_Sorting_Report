#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
using namespace std::chrono;

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
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("test_case/Merge_sort.out", "w", stdout);
  for(int testth=1; testth<=10; testth++) {
    string fname="test_case/Test_"+to_string(testth)+".inp";
    //FILE *fbuff = (fname, "r", stdin);
    ifstream fbuff(fname);
    fbuff >> n;
    for(int i=0; i<n; i++) fbuff >> a[i];
    fbuff.close();

    string name_case = "Test case " + to_string(testth);
    auto start = high_resolution_clock::now();
      Merge_sort(a);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << name_case << ": ";
    cout << (long double)duration.count() / 1000  << " ms" << endl;
  }
}

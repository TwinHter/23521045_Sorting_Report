#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
using namespace std::chrono;

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
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("test_case/Heap_sort.out", "w", stdout);
  for(int testth=1; testth<=10; testth++) {
    string fname="test_case/Test_"+to_string(testth)+".inp";
    //FILE *fbuff = (fname, "r", stdin);
    ifstream fbuff(fname);
    fbuff >> n;
    for(int i=0; i<n; i++) fbuff >> a[i];
    fbuff.close();

    string name_case = "Test case " + to_string(testth);
    auto start = high_resolution_clock::now();
      Heap_sort(a, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << name_case << ": " ;
    cout << (long double)duration.count() / 1000 << " ms" << endl;
  }
}
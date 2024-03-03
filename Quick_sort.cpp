#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
using namespace std::chrono;
const int SZ = 1000000 + 10;
int a[SZ], n, step;
int partition(int start, int end) {
  swap(a[start], a[start+(end-start)/2]);
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
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("test_case/Quick_sort.out", "w", stdout);
  for(int testth=1; testth<=10; testth++) {
    string fname="test_case/Test_"+to_string(testth)+".inp";
    //FILE *fbuff = (fname, "r", stdin);
    ifstream fbuff(fname);
    fbuff >> n;
    for(int i=0; i<n; i++) fbuff >> a[i];
    fbuff.close();

    string name_case = "Test case " + to_string(testth);
    auto start = high_resolution_clock::now();
      Quick_sort();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << name_case << ": " << (long double)duration.count() / 1000 << " ms" << endl;
  }
}
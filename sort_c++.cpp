#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
using namespace std::chrono;
const int SZ = 1000000 + 10;
int a[SZ], n;
void Sorting_function_of_cpp() {
  sort(a, a+n);
} 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("test_case/sort_c++.out", "w", stdout);
  for(int testth=1; testth<=10; testth++) {
    string fname="test_case/Test_"+to_string(testth)+".inp";
    //FILE *fbuff = (fname, "r", stdin);
    ifstream fbuff(fname);
    fbuff >> n;
    for(int i=0; i<n; i++) fbuff >> a[i];
    fbuff.close();

    string name_case = "Test case " + to_string(testth);
    auto start = high_resolution_clock::now();
      Sorting_function_of_cpp();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << name_case << ": ";
    cout << (long double)duration.count() / 1000 << " ms" << endl;
  }
}
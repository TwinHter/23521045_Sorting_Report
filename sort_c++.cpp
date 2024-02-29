// Using sorting function of cpp
#include<bits/stdc++.h>
using namespace std;

const int MX = (int)1e6 + 10;
int a[MX];
int main() {
  int n; cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }
  sort(a+1, a+1+n);
}
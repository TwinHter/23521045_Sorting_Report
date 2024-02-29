#include <bits/stdc++.h>
using namespace std;
const string NAME = "template";
#define ll long long

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    ll p = l-1;
    while(p < l || p > h) 
        p = l + rd() * 1LL * rd() % (h - l + 1);
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("sinh.out", "w", stdout);
    srand(time(NULL));
    string lowcase = "abcdefghijklmnopqrstuvwxyz";
    while(T--) {
      int n = 1000000; cin >> n;
      
    }
}
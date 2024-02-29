#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "template";
// Số test kiểm tra
const int NTEST = 100;
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
    int T = 100;
    cout << T << '\n';
    while(T--) {
        ll n, x;
        n = Rand(5e16, 1e17-1);
        x = Rand(1, 1e5);
        if(T % 20 == 0) x = n+1;
        cout << n << " " << x << '\n';
    }
}
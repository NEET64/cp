#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, r, y;
    cin >> n >> y >> r;

    int ans = 0;
    r = min(r, n);
    ans += r;
    n -= r;

    y = min(y / 2, n);
    ans += y;

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

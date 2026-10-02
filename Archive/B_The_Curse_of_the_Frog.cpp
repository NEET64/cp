#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;

    int mx = -1;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x -= (b - 1) * a;
        mx = max({ a * b - c, mx });
    }

    int ans = 0;

    if (x <= 0) cout << "0\n";
    else if (mx <= 0) cout << "-1\n";
    else {
        ans = (x + mx - 1) / mx;
        cout << ans << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
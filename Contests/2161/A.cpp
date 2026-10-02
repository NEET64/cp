#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int r, x, d, n;
    cin >> r >> x >> d >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (char c : s) {
        if (c == '1') {
            ans++;
            r -= d;
        }
        else if (r < x) {
            ans++;
            r -= d;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

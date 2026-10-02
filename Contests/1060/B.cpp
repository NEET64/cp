#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int mx = 0;
    for (int i = 0;i < n;i++) {
        mx = max(mx, ar[i]);
        if (i % 2) {
            ar[i] = mx;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        int prev = i > 0 ? ar[i - 1] : LLONG_MAX;
        int next = i < n - 1 ? ar[i + 1] : LLONG_MAX;
        ans += max(0LL, ar[i] - (min(prev, next) - 1));
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

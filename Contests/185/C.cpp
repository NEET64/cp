#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> q(n);
    vector<int> r(n);

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    sort(q.rbegin(), q.rend());
    sort(r.begin(), r.end());

    int ans = 0;
    int p = 0;
    for (int i = 0; i < n and p < n; i++) {
        if (q[i] + 1 <= (k + 1) / (r[p] + 1)) {
            ans++;
            p++;
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

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + ar[i];

    vector<int> consec(n + 1, 0);
    for (int i = 1; i < n; i++) {
        consec[i + 1] = consec[i] + (ar[i] == ar[i - 1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int m = r - l + 1;

        int ones = pre[r + 1] - pre[l];
        int zeros = m - ones;

        if (m % 3 != 0 || ones % 3 != 0 || zeros % 3 != 0) {
            cout << -1 << "\n";
            continue;
        }

        bool has_consec = (consec[r + 1] - consec[l + 1] > 0);

        int ans = ones / 3 + zeros / 3;
        if (!has_consec) ans++;

        cout << ans << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

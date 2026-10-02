#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    int dp1 = 0;
    int dp2 = 0;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    for (int g1 = 0; g1 < n; g1++) {
        bool valid = true;
        for (int i = 0, j = g1; i < n; i++, j = (j + 1) % n) {
            if (a[i] >= b[j]) {
                valid = false;
                break;
            }
        }
        if (valid) dp1++;
    }

    for (int g2 = 0; g2 < n; g2++) {
        bool valid = true;
        for (int i = 0, j = g2; i < n; i++, j = (j + 1) % n) {
            if (b[i] >= c[j]) {
                valid = false;
                break;
            }
        }
        if (valid) dp2++;
    }

    cout << dp1 * dp2 * n << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
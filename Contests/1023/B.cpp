#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[j] % a[i]) % 2 == 0) {
                cout << a[i] << " " << a[j] << "\n";
                found = true;
                break;
            }
        }
    }
    if (!found) cout << -1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

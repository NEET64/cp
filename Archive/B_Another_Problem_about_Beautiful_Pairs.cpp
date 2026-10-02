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

    int root = sqrt(n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int k = 1; k < root; k++) {
            int t = i - ar[i] * k;
            if (t >= 0 && t < n && ar[t] == k) ans++;
        }

        for (int k = root; k < n; k++) {
            int t = i - ar[i] * k;
            if (t >= 0 && t < n && ar[t] == k) ans++;
        }
    }

    cout << ans << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];

        int left = i > 0 ? __gcd(a[i - 1], a[i]) : 1;
        int right = i < n - 1 ? __gcd(a[i + 1], a[i]) : 1;

        if ((left * right) / __gcd(left, right) < a[i]) {
            ans++;
        }

    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        solve();
    }
}
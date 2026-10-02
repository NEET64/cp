#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n + n);

    for (int i = 0; i < n + n; i++) {
        cin >> ar[i];
    }

    map<int, int> mp;
    for (int i : ar) mp[i]++;
    int odd = 0;
    int even = 0;
    for (auto& [k, v] : mp) {
        if (v % 2 == 1) odd++;
        else even++;
    }

    int ans = odd + 2 * even;

    if (!odd) {
        if (even % 2 != n % 2) ans -= 2;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

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

    sort(ar.begin(), ar.end());

    long long sum = accumulate(ar.begin(), ar.end(), 0LL);
    long long cur = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cur += ar[i] > 0;
        if (sum - cur < n - 1) {
            break;
        }
        if (ar[i] > 0) ans++;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

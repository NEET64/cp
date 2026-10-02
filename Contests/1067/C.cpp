#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int mx = LLONG_MIN;
    int cur = 0;

    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            cur += a[i];
            mx = max(mx, cur);
            if (cur < 0) cur = 0;
        }
    }
    else {
        int notadd = LLONG_MIN;
        int added = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            int now = max(0LL, notadd) + a[i] + b[i];
            int prev = (added == LLONG_MIN) ? LLONG_MIN : added + a[i];

            added = max(now, prev);
            int never = max(0LL, notadd) + a[i];
            notadd = never;

            mx = max(mx, added);
        }
    }

    cout << mx << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

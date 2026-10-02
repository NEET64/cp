#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ar(n);
    vector<int> st(n), en(n);
    int l = 0, r = n;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        st[a] = 1;
        en[b] = 1;
        l = max(l, a);
        r = min(r, b);
    }

    vector<int> ans(n, -1);
    int val = 0;
    if (l <= r) {
        ans[l] = 0;
        val = 1;
    }
    else {
        bool found = false;
        val = 2;
        for (int i = 0; i < n; i++) {
            if (st[i] && en[i]) continue;
            if (st[i] && i != n - 1) {
                ans[i] = 0;
                ans[i + 1] = 1;
                found = true;
                break;
            }
            else if (i != 0) {
                ans[i] = 0;
                ans[i - 1] = 1;
                found = true;
                break;
            }
        }
        if (!found) {
            ans[0] = 0;
            ans[n - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) ans[i] = val++;
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

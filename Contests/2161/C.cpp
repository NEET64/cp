#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort(ar.begin(), ar.end());

    int ans = 0;
    vector<int> order;

    int l = 0, r = n - 1;
    int left = 0LL;
    while (l <= r) {
        if (left + ar[r] >= x) {
            ans += ar[r];
            left = (left + ar[r]) % x;
            order.push_back(ar[r]);
            r--;
            continue;
        }
        left += ar[l];
        order.push_back(ar[l]);
        l++;
    }

    if (n == 1 && order.size() == 0) order.push_back(ar[0]);

    cout << ans << "\n";
    for (int i : order) cout << i << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

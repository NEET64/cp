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

    int ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (ar[i] - last > 1) {
            ans++;
            last = ar[i];
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
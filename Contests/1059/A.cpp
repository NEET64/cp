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
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += ar[j];
            ans = max(ans, sum / (j - i + 1));
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

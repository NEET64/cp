#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    string ar;
    cin >> n >> k >> ar;

    int c1 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((i - k) >= 0 && ar[i - k] == '1') c1--;

        if (ar[i] == '1') {
            if (c1 == 0) ans++;

            c1++;
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

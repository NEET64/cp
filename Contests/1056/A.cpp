#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    int win = n;

    int ans = 0;
    while (win > 1) {
        ans += win / 2;
        win = win / 2 + win % 2;
    }

    int lose = n - 1;
    while (lose > 1) {
        ans += lose / 2;
        lose = lose / 2 + lose % 2;

    }

    cout << (ans + 1) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

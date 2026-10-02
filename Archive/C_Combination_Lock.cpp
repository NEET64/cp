#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "-1\n"; return;
    }

    for (int i = n; i > 0; i--) {
        cout << i << " ";
    }
    cout << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    int k = 1;
    while (k <= x || k <= y || k <= z) {
        int sum = ((k & x) != 0) + ((k & y) != 0) + ((k & z) != 0);
        if (sum == 2) {
            cout << "No\n";
            return;
        }
        k <<= 1;
    }
    cout << "Yes\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

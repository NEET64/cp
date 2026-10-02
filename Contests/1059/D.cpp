#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int l, int r) {
    int before, after;
    cout << 1 << " " << l << " " << r << endl;
    cin >> before;
    cout << 2 << " " << l << " " << r << endl;
    cin >> after;
    return (after - before);
}

void solve() {
    int n;
    cin >> n;

    int l = 1, r = n, left = n + 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (!(query(1, m) == 0)) {
            left = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    int total = query(1, n);

    cout << "! " << left << " " << left + total - 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}

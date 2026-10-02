#include <bits/stdc++.h>
using namespace std;
#define int long long

int get(int r) {
    return r - r/2 - r/3 - r/5 - r/7 + r/6 + r/10 + r/14 + r/15 + r/21 + r/35 - r/30 - r/42 - r/70 - r/105 + r/210;
}

void solve() {
    int l, r;
    cin >> l >> r;

    cout << get(r)-get(l-1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}
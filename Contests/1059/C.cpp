#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;

    int lefta = 31 - __builtin_clz(a);
    int leftb = 31 - __builtin_clz(b);



    if (lefta < leftb) {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans;
    for (int i = lefta; i >= 0; i--) {
        if (((a >> i) & 1) == 0) {
            ans.push_back((1 << i));
        }
    }

    for (int i = lefta; i >= 0; i--) {
        if (((b >> i) & 1) == 0) {
            ans.push_back((1 << i));
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

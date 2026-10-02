#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    set<int> ar;
    for (int i = 0; i < n; i++) {
        int cur; cin >> cur;
        ar.insert(cur);
    }

    cout << ar.size() * 2 - 1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

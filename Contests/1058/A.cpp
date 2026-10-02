#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    set<int> ar;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ar.insert(x);
    }
    int test = 0;
    while (true) {
        if (ar.count(test)) {
            test++;
        }
        else {
            cout << test << "\n";
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

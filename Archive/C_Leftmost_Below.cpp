#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    bool fail = false;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int mn = ar[0];

    for (int i = 1; i < n; i++) {
        if (ar[i]-mn >= mn) {
            fail = true;
            break;
        }
        mn = min(mn, ar[i]);
}

    if(fail) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  

    int t; cin >> t;

    while (t--) solve();
}
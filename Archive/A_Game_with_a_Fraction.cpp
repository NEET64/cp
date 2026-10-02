#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;

    cin >> a >> b;

    if (a < b and a * 3 >= 2L * b) cout << "Bob\n";
    else cout << "Alice\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
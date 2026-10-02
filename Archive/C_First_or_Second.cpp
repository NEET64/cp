#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }


    int min = ar[0];
    for (int i : ar) min -= i;
    int x = min;

    min += ar[1];
    min += ar[0];
    x = max(x, min);

    for (int i = 2; i < n; i++) {
        min += ar[i];
        min += max(ar[i - 1], -ar[i - 1]);
        x = max(x, min);
    }

    cout << x << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}
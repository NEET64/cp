#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<string> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (char c : ar[i]) {
            if (c == '#') total++;
        }
    }

    for (int k = -n; k < n; k++) {
        int ct = 0;
        int j = k;
        for (int i = 0; i < n; i++) {
            if (j >= 0 and j < n and ar[i][j] == '#') ct++;
            j++;
            if (j >= 0 and j < n and ar[i][j] == '#') ct++;
        }
        if (ct == total) {
            cout << "YES\n";
            return;
        }
    }


    for (int k = 0; k <= n + n; k++) {
        int ct = 0;
        int j = k;
        for (int i = 0; i < n; i++) {
            if (j >= 0 and j < n and ar[i][j] == '#') ct++;
            j--;
            if (j >= 0 and j < n and ar[i][j] == '#') ct++;
        }
        if (ct == total) {
            cout << "YES\n";
            return;
        }
    }

    int block = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (ar[i][j] == '#' and ar[i][j + 1] == '#' and ar[i + 1][j] == '#' and ar[i + 1][j + 1] == '#') block++;
        }
    }
    if (block == 1 and total == 4) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

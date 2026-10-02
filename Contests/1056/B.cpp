#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    if (n * n - 1 == k) {
        cout << "No" << "\n";
        return;
    }

    vector<vector<char>> grid(n, vector<char>(n, 'D'));
    for (int j = 0; j < n - 1; j++) grid[n - 1][j] = 'R';
    grid[n - 1][n - 1] = 'L';


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k-- > 0) grid[i][j] = 'U';
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    int t = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = t++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int up = i > 0 ? mat[i - 1][j] : 0;
            int down = i < n - 1 ? mat[i + 1][j] : 0;
            int left = j > 0 ? mat[i][j - 1] : 0;
            int right = j < n - 1 ? mat[i][j + 1] : 0;
            ans = max(ans, up + down + left + right + mat[i][j]);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      ans = max(ans, mat[i][j]);
    }
  }

  vector<int> col(m, 0);
  vector<int> row(n, 0);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == ans) {
        col[j]++; row[i]++;
        cnt++;
      }
    }
  }

  bool found = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = col[j] + row[i];
      if ((mat[i][j] == ans && (sum == cnt + 1)) || (sum == cnt)) {
        found = true;
        break;
      }
    }
    if (found) break;
  }

  if (found) cout << ans - 1 << "\n";
  else cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
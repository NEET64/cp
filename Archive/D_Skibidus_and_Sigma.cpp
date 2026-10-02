#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> ar(n, vector<int>(m + 1));

  for (int i = 0; i < n; i++) {
    int cur = 0LL;
    for (int j = 0; j < m; j++) {
      cin >> ar[i][j];
      cur += ar[i][j];
    }
    ar[i][m] = cur;
  }
  sort(ar.begin(), ar.end(), [](const vector<int>& a, const vector<int>& b) {
    int sz = a.size();
    return a[sz - 1] > b[sz - 1];
    });

  int t = n * m;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // cout << ar[i][j] << " ";

      ans += t * ar[i][j];
      t--;
    }
    // cout << endl;
  }
  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  int LG = 21;

  vector<vector<int>> spt(LG, vector<int>(n, 0));
  for (int i = 0; i < n; i++) cin >> spt[0][i];

  for (int k = 1; k < LG; k++) {
    for (int i = 0; i + (1 << k) <= n; i++) {
      spt[k][i] = gcd(spt[k - 1][i], spt[k - 1][i + (1 << (k - 1))]);
    }
  }

  int q; cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    int m = r - l + 1;
    int k = 0;
    while ((1 << (k + 1)) <= m) k++;

    int ans = gcd(spt[k][l], spt[k][r - (1 << k) + 1]);
    cout << ans << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
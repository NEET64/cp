#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++)cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        ans.push_back({ 1, j + 1 });
        swap(a[j], a[j + 1]);
      }
      if (b[j] > b[j + 1]) {
        ans.push_back({ 2, j + 1 });
        swap(b[j], b[j + 1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      ans.push_back({ 3, i + 1 });
    }
  }

  cout << ans.size() << "\n";
  for (auto x : ans) cout << x.first << " " << x.second << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
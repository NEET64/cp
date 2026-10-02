#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];

  sort(ar.rbegin(), ar.rend());
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int goal = max(ar[i] * 2, ar[0]) - ar[i] - ar[j];
      int idx = lower_bound(ar.begin() + j + 1, ar.end(), goal, greater<int>()) - ar.begin();
      ans += idx - (j + 1);
    }
  }

  cout << ans << "\n";
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}

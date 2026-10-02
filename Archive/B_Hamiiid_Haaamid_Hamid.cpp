#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (k == 1 || k == n) {
    cout << "1\n";
    return;
  }
  int INF = LLONG_MAX;
  k--;
  int left = -INF, right = INF;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      if (i < k) left = i;
      if (i > k && right == INF) right = i;
    }
  }

  if (left == -INF && right == INF) {
    cout << "1\n";
    return;
  }

  cout << max(min(k + 1, n - right + 1), min(left + 2, n - k)) << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}

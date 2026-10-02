#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> ar(n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    ans += __builtin_popcount(ar[i]);
  }

  for (int i = 0; i < 60; i++) {
    int mask = (1LL << i);
    for (int i : ar) {
      if (!(mask & i) && k >= mask) {
        k -= mask;
        ans++;
      }
    }
    if (k <= mask) break;
  }

  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
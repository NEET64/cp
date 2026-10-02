#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n);
  vector<int> bitcount(30);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];

    for (int k = 0; k < 30; k++) {
      bitcount[k] += (ar[i] >> k) & 1;
    }
  }

  int ans = 0;

  for (int num : ar) {
    int cur = 0;
    for (int k = 0; k < 30; k++) {
      bool setbit = (num >> k) & 1;

      if (setbit) {
        cur += (n - bitcount[k]) * (1 << k);
      }
      else cur += bitcount[k] * (1 << k);
    }
    ans = max(ans, cur);
  }

  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
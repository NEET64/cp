#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  int all = 0;
  bool fail = false;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) {
    if ((i | k) != k) {
      fail = true;
      break;
    }
    all |= i;
    ar[i] = i;
  }

  if (fail || all != k) ar[n - 1] = k;

  for (int i : ar) cout << i << " ";


  cout << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
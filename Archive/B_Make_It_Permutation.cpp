#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;
  int k = 1;
  cout << 2 * n - 1 << "\n";
  for (int i = 1; i < n; i++) {
    cout << i << " " << 1 << " " << k++ << "\n";
    cout << i << " " << k << " " << n << "\n";
  }
  cout << n << " " << 1 << " " << k << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int one = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') one++;
  }
  if (one <= k) {
    cout << "Alice\n";
    return;
  }

  if (k > n / 2) {
    cout << "Alice\n";
  }
  else cout << "Bob\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
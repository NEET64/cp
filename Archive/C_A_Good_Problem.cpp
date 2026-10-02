#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, l, r, k;
  cin >> n >> l >> r >> k;

  int bit = 64 - __builtin_clzll(l);
  int next = (1LL << bit);

  /*
    if odd then answer is l

    if even,
      possible , next<=r;

      if(k == n or n-1) then next
      else l;
      impossible, next>r;
    */

  if (n % 2 == 0) {
    if (next <= r && n > 2) {
      if (k == n || k == n - 1) cout << next << "\n";
      else cout << l << "\n";
    }
    else cout << -1 << "\n";
  }
  else cout << l << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
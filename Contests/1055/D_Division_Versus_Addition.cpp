#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> bit_count(n + 1);
  vector<int> count_101(n + 1);

  for (int i = 1; i <= n; i++) {
    int cur; cin >> cur;
    bit_count[i] = 31 - __builtin_clz(cur);
    int count = __builtin_popcount(cur);
    if (count > 2) {
      bit_count[i]++;
    }

    if (count == 2) {
      if (cur & 1) {
        count_101[i] = 1;
      }
      else {
        bit_count[i]++;
      }
    }
    count_101[i] += count_101[i - 1];
    bit_count[i] += bit_count[i - 1];
  }


  // for (int i : bit_count) cout << i << " ";
  // cout << "\n";

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << (bit_count[r] - bit_count[l - 1] + (count_101[r] - count_101[l - 1]) / 2) << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
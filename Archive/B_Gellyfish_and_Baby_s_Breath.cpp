#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 998244353;
int pow2[(int)1e5 + 1];

void solve() {
  int n;
  cin >> n;

  vector<int> p(n);
  vector<int> q(n);

  for (int& i : p) cin >> i;
  for (int& i : q) cin >> i;

  int maxp = 0, maxq = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > p[maxp]) maxp = i;
    if (q[i] > q[maxq]) maxq = i;

    int ans;

    if (p[maxp] == q[maxq]) {
      ans = (pow2[p[maxp]] + pow2[max(q[i - maxp], p[i - maxq])]) % mod;
    }
    else if (p[maxp] > q[maxq]) {
      ans = (pow2[p[maxp]] + pow2[q[i - maxp]]) % mod;
    }
    else ans = (pow2[q[maxq]] + pow2[p[i - maxq]]) % mod;

    cout << ans << " ";
  }


  cout << "" << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  pow2[0] = 1;
  for (int i = 1; i <= 1e5; i++) {
    pow2[i] = (pow2[i - 1] * 2) % mod;
  }

  while (t--) solve();
}
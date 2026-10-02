#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k;
  cin >> n >> k;

  vector<tuple<int, int, int>> v;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(make_tuple(a, b, c));
  }

  sort(v.begin(), v.end());

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (k >= get<0>(v[i])) {
      k = max(k, get<2>(v[i]));
    }
  }

  cout << k << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
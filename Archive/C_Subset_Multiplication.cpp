#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n);

  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int last = 1;
  for (int i = 1; i < n; i++) {
    last = lcm(last, (ar[i - 1] / gcd(ar[i], ar[i - 1])));
  }


  cout << last << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
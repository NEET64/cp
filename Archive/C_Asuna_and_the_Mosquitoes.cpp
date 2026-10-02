#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n);
  int odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];

    if (ar[i] % 2 != 0) odd++;
  }

  if (odd == 0 || odd == n) {
    cout << *max_element(ar.begin(), ar.end()) << "\n";
    return;
  }

  int ans = accumulate(ar.begin(), ar.end(), 0LL);


  cout << ans - odd + 1 << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n);
  int dif = LLONG_MAX;

  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  for (int i = 1; i < n; i++) {
    int cur = ar[i] - ar[i - 1];
    if (dif == LLONG_MAX) dif = cur;
    else if (cur != dif) {
      cout << "No\n";
      return;
    }
  }
  if ((ar[0] - dif) % (n + 1) != 0) {
    cout << "No\n";
    return;
  }
  int q = (ar[0] - dif) / (n + 1);
  int p = dif + q;

  // cout << p << " " << q << "\n";
  if (p >= 0 && q >= 0) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
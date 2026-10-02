#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n);

  int z = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] == 0) z++;
  }

  if (z == 0) {
    cout << "1\n";
    cout << 1 << " " << n << "\n";
    return;
  }

  if (ar[0] != 0) {
    cout << "2\n";
    cout << 2 << " " << n << "\n";
  }
  else if (ar[n - 1] != 0) {
    cout << "2\n";
    cout << 1 << " " << n - 1 << "\n";
  }
  else {
    cout << "3\n";
    cout << 1 << " " << 2 << "\n";
    cout << 2 << " " << n - 1 << "\n";
  }
  cout << 1 << " " << 2 << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
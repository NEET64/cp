#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int cnum) {
  int n, a, b;
  cin >> n >> a >> b;

  cout << "Case #" << cnum << ": ";

  for (int i = 0; i < n + n - 1; i++) {
    cout << 1 << " ";
  }
  cout << b << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  for (int i = 0; i < t; i++) {
    solve(i + 1);
  }
}
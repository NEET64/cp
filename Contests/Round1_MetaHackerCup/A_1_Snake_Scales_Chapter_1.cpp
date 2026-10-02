#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int cnum) {
  int n;
  cin >> n;

  vector<int> ar(n);

  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, abs(ar[i] - ar[i - 1]));
  }

  cout << "Case #" << cnum << ": " << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  for (int i = 0; i < t; i++) {
    solve(i + 1);
  }
}
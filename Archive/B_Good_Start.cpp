#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int w, h, a, b;
  cin >> w >> h >> a >> b;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int mn = LLONG_MAX;
  if (y2 > y1) {
    if (y2 - y1 - b > 0) {
      mn = min(mn, y2 - y1 - b);
    }
  }
  else {
    if (y1 - y2 - b > 0) {
      mn = min(mn, y1 - y2 - b);
    }
  }

  if (mn != LLONG_MAX and mn % b == 0) {
    cout << "Yes\n";
    return;
  }

  mn = LLONG_MAX;

  if (x2 > x1) {
    if (x2 - x1 - a > 0)
      mn = min(mn, x2 - x1 - a);
  }
  else {
    if (x1 - x2 - a > 0) {
      mn = min(mn, x1 - x2 - a);
    }
  }

  if (mn != LLONG_MAX and mn % a == 0) cout << "Yes\n";
  else cout << "No\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
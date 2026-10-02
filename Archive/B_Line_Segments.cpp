#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int px, py, qx, qy;
  cin >> px >> py >> qx >> qy;

  vector<int> dis(n);
  for (int i = 0; i < n; i++) {
    cin >> dis[i];
  }

  int sum = accumulate(dis.begin(), dis.end(), 0LL);
  sort(dis.begin(), dis.end());

  int right = sum;
  int left = 0;
  int mn = sum;
  for (int i = 0; i < n - 1; i++) {
    left += dis[i];
    right -= dis[i];
    mn = min(mn, (right - left));
  }

  double distance = (double)sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));

  if (distance <= sum && distance >= mn) cout << "Yes\n";
  else cout << "No\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
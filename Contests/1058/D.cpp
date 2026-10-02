#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> ans(2 * n, -1);
  set<int> found, exclude;

  for (int i = 2; i <= 2 * n; i++) {
    vector<int> q;
    for (int j = 1; j <= i; j++)
      if (!exclude.count(j)) q.push_back(j);

    cout << "? " << q.size() << " ";
    for (int x : q) cout << x << " ";
    cout << endl;

    int mx; cin >> mx;
    if (found.count(mx) || mx == 0) continue;

    ans[i - 1] = mx;
    found.insert(mx);
    exclude.insert(i);
  }

  vector<int> q(exclude.begin(), exclude.end());
  for (int i = 1; i <= 2 * n; i++) {
    if (ans[i - 1] != -1) continue;

    cout << "? " << q.size() + 1 << " ";
    for (int x : q) cout << x << " ";
    cout << i << " ";
    cout << endl;

    int mx;
    if (!(cin >> mx)) return;
    ans[i - 1] = mx;
  }

  cout << "! ";
  for (int x : ans) cout << x << " ";
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) solve();
}

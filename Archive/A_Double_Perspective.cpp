#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> ar(n, vector<int>(4));

  for (int i = 0; i < n; i++) {
    int l, r, m;
    cin >> l >> r;
    m = r - l + 1;
    ar[i] = { -m, l, r, i + 1 };
  }

  sort(ar.begin(), ar.end());
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    vector<int> cur = ar[i];
    bool fail = false;
    for (int idx : ans) {
      if (cur[1] >= ar[idx][1] && cur[2] <= ar[idx][2]) {
        fail = true;
        break;
      }
    }
    if (!fail) ans.push_back(i);
  }

  cout << ans.size() << "\n";
  for (int i : ans) cout << ar[i][3] << " ";
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
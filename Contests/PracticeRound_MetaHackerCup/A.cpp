#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int test) {
  int n;
  cin >> n;

  vector<vector<int>> cur(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> cur[i][0];
    cur[i][2] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    cin >> cur[i][1];
  }
  sort(cur.begin(), cur.end());
  vector<pair<int, int>> ans;
  bool fail = false;
  for (int i = 0; i < n; i++) {
    if (cur[i][0] == cur[i][1]) continue;
    bool found = false;
    for (int j = i + 1; j < n; j++) {
      if (max(cur[i][0], cur[j][0]) == cur[i][1]) {
        ans.push_back({ cur[j][2], cur[i][2] });
        found = true;
        break;
      }
    }
    if (!found) {
      fail = true;
      break;
    }
  }

  cout << "Case #" << test << ": ";
  if (fail) {
    cout << -1 << endl;
  }
  else {
    cout << ans.size() << endl;
    for (auto x : ans) {
      cout << x.first << " " << x.second << endl;
    }
  }

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  for (int i = 1; i <= t; i++) solve(i);
}


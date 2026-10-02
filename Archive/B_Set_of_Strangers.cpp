#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  unordered_set<int> st;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      st.insert(mat[i][j]);
    }
  }

  unordered_set<int> adj;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (mat[i][j] == mat[i][j - 1]) {
        adj.insert(mat[i][j]);
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == mat[i - 1][j]) {
        adj.insert(mat[i][j]);
      }
    }
  }

  int sharing = adj.size();
  int total = st.size();

  cout << total - 1 + (sharing ? sharing - 1 : 0) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
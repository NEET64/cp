#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<vector<int>> mat(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<int> st(2 * n);
      for (int k = i - 1; k >= 0; k--) st[mat[k][j]]++;
      for (int k = j - 1; k >= 0; k--) st[mat[i][k]]++;
      int mex = 0;
      while (st[mex] != 0) mex++;
      mat[i][j] = mex;
      cout << mex << " ";
    }
    cout << "\n";
  }

}
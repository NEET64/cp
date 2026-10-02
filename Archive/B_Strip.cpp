#include <bits/stdc++.h>
using namespace std;
#define int long long

bool validDiff(int l, int r, int S, int L, vector<vector<int>>& mx, vector<vector<int>>& mn, vector<int>& lg) {
  int m = r - l + 1;
  int k = lg[m];
  return m >= L && max(mx[k][l], mx[k][r - (1 << k) + 1]) - min(mn[k][l], mn[k][r - (1 << k) + 1]) <= S;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, s, l;
  cin >> n >> s >> l;

  int LG = 17;

  vector<int> lg(n + 1);
  for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

  vector<vector<int>> mx(LG, vector<int>(n));
  vector<vector<int>> mn(LG, vector<int>(n));

  for (int i = 0; i < n; i++) {
    cin >> mx[0][i];
    mn[0][i] = mx[0][i];
  }

  for (int k = 1; k < LG; k++) {
    for (int i = 0; i + (1 << k) <= n; i++) {
      mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + (1 << (k - 1))]);
      mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
    }
  }

  vector<int> dp(n, INT_MAX);


  for (int i = l - 1; i < n; i++) {
    for (int start = 0; start + l <= i + 1; start++) {
      if (validDiff(start, i, s, l, mx, mn, lg)) {
        int prev = start == 0 ? 0 : dp[start - 1];
        dp[i] = min(dp[i], prev + 1);
      }
    }
  }


  cout << (dp[n - 1] >= INT_MAX ? -1 : dp[n - 1]) << "\n";
}
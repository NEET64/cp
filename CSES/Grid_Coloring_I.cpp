#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<string> ar(n);

  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (ar[i][j] == 'A') ar[i][j] = 'C';
        else ar[i][j] = 'A';
      }
      else {

        if (ar[i][j] == 'B') ar[i][j] = 'D';
        else ar[i][j] = 'B';
      }
    }
  }

  for (auto& s : ar) cout << s << "\n";
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<string>> ar = { {"12", "21"}, {"123", "132", "213", "231", "312", "321"}, {"1234", "1243", "1324", "1342", "1423", "1432", "2134", "2143", "2314", "2341", "2413", "2431", "3124", "3142", "3214", "3241", "3412", "3421", "4123", "4132", "4213", "4231", "4312", "4321"} };

void solve() {
  int n, i, j;
  cin >> n >> i >> j;

  i--; j--;
  n = n == 12 ? 0 : n == 123 ? 1 : 2;

  string a = ar[n][i % ar[n].size()];
  string b = ar[n][j % ar[n].size()];

  int A = 0;
  int B = 0;

  for (int i = 0;i < a.size();i++) {
    if (a[i] == b[i]) A++;
  }

  cout << A << "A" << a.size() - A << "B" << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}

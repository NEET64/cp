#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int N, A, B;
  cin >> N >> A >> B;

  if (A + B > N || ((A == 0 || B == 0) && !(A == 0 && B == 0))) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";

  for (int i = 0, n = N; i < A; i++, n--) cout << n << " ";
  for (int n = N - A - B; n > 0; n--) cout << n << " ";
  for (int i = 0, n = N - A; i < B; i++, n--) cout << n << " ";

  cout << "\n";

  for (int i = 0, n = N - B; i < A; i++, n--) cout << n << " ";
  for (int n = N - A - B; n > 0; n--) cout << n << " ";
  for (int i = 0, n = N; i < B; i++, n--) cout << n << " ";

  cout << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
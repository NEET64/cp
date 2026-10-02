#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<int>& ar, int lad) {
  int n = ar.size();
  vector<int> seen(n, -1);

  if (ar[0] <= lad) seen[0] = 1;
  if (ar[n - 1] <= lad) seen[n - 1] = 1;

  for (int i = 1; i < n; i++) {
    if (ar[i] <= lad) seen[i] = 1;
    else if (seen[i - 1] == 1 && abs(ar[i] - ar[i - 1]) <= lad) seen[i] = 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    if (ar[i] <= lad) seen[i] = 1;
    else if (seen[i + 1] == 1 && abs(ar[i] - ar[i + 1]) <= lad) seen[i] = 1;
  }

  for (int i : seen) if (i == -1) return false;

  return true;
}

void solve(int cnum) {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];

  int l = *min_element(ar.begin(), ar.end());
  int r = *max_element(ar.begin(), ar.end());
  int ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(ar, mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }

  cout << "Case #" << cnum << ": " << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  for (int i = 0;i < t;i++) solve(i + 1);
}

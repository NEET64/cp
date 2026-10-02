#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  map<int, int> mp;
  mp[0] = -1;
  int c1 = 0, c0 = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') c0++;
    else c1++;

    int key = c0 - c1;
    if (mp.count(key)) ans = max(ans, i - mp[key]);

    if (!mp.count(key)) mp[key] = i;
  }

  cout << ans << "\n";
}
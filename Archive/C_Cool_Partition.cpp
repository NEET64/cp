#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  vector<int> ar(n);
  map<int, int> freq;
  set<int> prev;
  set<int> cur;

  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    freq[ar[i]]++;
  }

  int ans = 1;

  for (int i = 0; i < n; i++) {
    freq[ar[i]]--;
    if (freq[ar[i]] == 0) break;
    else {
      if (prev.count(ar[i])) {
        prev.erase(ar[i]);
      }
      cur.insert(ar[i]);
    }

    if (prev.size() == 0) {
      ans++;
      set<int>* temp = &prev;
      set<int>* temp2 = &cur;
      prev = *temp2;
      cur = *temp;
    }
  }

  cout << ans << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
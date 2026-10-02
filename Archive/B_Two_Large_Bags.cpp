#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n;
  cin >> n;

  vector<int> ar(n);
  vector<int> freq(2001, 0);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    freq[ar[i]]++;
  }

  for (int i = 0; i < 2000; i++) {
    if (freq[i] > 2) {
      freq[i + 1] += freq[i] - 2;
    }
    else if (freq[i] == 1) {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  while (t--) solve();
}
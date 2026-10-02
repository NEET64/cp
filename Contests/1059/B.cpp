#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') ans.push_back(i + 1);
    }


    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

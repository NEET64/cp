#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int total_a = count(s.begin(), s.end(), 'a');
    int total_b = n - total_a;
    int diff = total_a - total_b;

    if (diff == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> pref(n + 1, 0);
    map<int, int> mp;
    mp[0] = 0;

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (s[i] == 'a' ? 1 : -1);

    int ans = n;

    for (int i = 1; i <= n; i++) {
        int tar = pref[i] - diff;
        if (mp.count(tar)) {
            int l = mp[tar];
            if (i - l < ans) {
                ans = i - l;
            }
        }
        mp[pref[i]] = i;
    }

    cout << (ans == n ? -1 : ans) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
    }

    vector<int> odd;
    int ans = 0LL;
    int count = 0;
    for (auto& [key, val] : mp) {
        if (val % 2 == 0) {
            ans += key * val;
            count += val;
        }
        else {
            count += (val - 1);
            ans += key * (val - 1);
            odd.push_back(key);
        }
    }

    sort(odd.begin(), odd.end());
    bool found = false;
    for (int i = odd.size() - 1; i > 0; i--) {
        int dif = odd[i] - odd[i - 1];
        if (dif < ans) {
            found = true;
            ans += (odd[i] + odd[i - 1]);
            count += 2;
            break;
        }
    }

    if (!found) {
        for (int i : odd) {
            if (i < ans) {
                ans += i;
                count++;
                break;
            }
        }
    }


    if (count > 2)
        cout << ans << "\n";
    else cout << 0 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

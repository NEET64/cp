#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    vector<int> lock(n);
    vector<int> unlock;

    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < n; i++) {
        cin >> lock[i];
        if (lock[i] == 0) unlock.push_back(ar[i]);
    }

    sort(unlock.begin(), unlock.end());
    int t = 0;
    for (int i = 0;i < n;i++) {
        if (lock[i] == 0) {
            ar[i] = unlock[t++];
        }
    }

    for (int i : ar) cout << i << " ";

    cout << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) solve();
}